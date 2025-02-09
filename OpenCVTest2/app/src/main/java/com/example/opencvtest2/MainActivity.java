package com.example.opencvtest2;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.ImageFormat;
import android.graphics.Matrix;
import android.graphics.Rect;
import android.graphics.SurfaceTexture;
import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraCaptureSession;
import android.hardware.camera2.CameraCharacteristics;
import android.hardware.camera2.CameraDevice;
import android.hardware.camera2.CameraManager;
import android.hardware.camera2.CaptureRequest;
import android.hardware.camera2.TotalCaptureResult;
import android.hardware.camera2.params.StreamConfigurationMap;
import android.media.Image;
import android.media.ImageReader;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.HandlerThread;
import android.util.Log;
import android.util.Range;
import android.util.Size;
import android.util.SparseIntArray;
import android.view.Surface;
import android.view.TextureView;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.opencvtest2.databinding.ActivityMainBinding;

import org.opencv.android.Utils;
import org.opencv.core.Mat;
import org.opencv.core.MatOfByte;
import org.opencv.imgcodecs.Imgcodecs;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private final String[] REQUIRED_PERMISSIONS = new String[]{"android.permission.CAMERA",
            "android.permission.WRITE_EXTERNAL_STORAGE"};
    private final int REQUEST_PERMISSIONS_CODE = 1000;
    private final String TAG = "Main";

    private TextureView textureView;
    private Button button;
    private Button zoomButton;
    private ImageView imageView;

    // thread
    private HandlerThread backgroundThread;
    private Handler backgroundHandler;
    private HandlerThread imageThread;
    private Handler imageHandler;

    Handler handler = new Handler();


    // 이미지
    private Size imageSize;
    private ImageReader imageReader;

    // 이미지 저장
    private File file;

    // 카메라
    // 카메라 번호(후면, 전면, 광각 등..)
    private String cameraId;
    private CameraDevice cameraDevice;
    private CaptureRequest.Builder captureRequestBuilder;
    private CameraCaptureSession cameraCaptureSession;
    private CameraCharacteristics cameraCharacteristics;

    // 카메라 줌인/아웃
    private float maxZoom;
    private float nowZoom = 1.0f;
    private Rect sensorSize;
    private Rect cropRegion;

    // 회전
    private static final SparseIntArray ORIENTATIONS = new SparseIntArray();
    static {
        ORIENTATIONS.append(Surface.ROTATION_0, 90);
        ORIENTATIONS.append(Surface.ROTATION_90, 0);
        ORIENTATIONS.append(Surface.ROTATION_180, 270);
        ORIENTATIONS.append(Surface.ROTATION_270, 180);
    }

    // JNI
    static {
        System.loadLibrary("opencv_java4");
        System.loadLibrary("native-lib");
    }
    public native void ConvertRGBtoGray(long matAddrInput, long matAddrResult);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 카메라 권한 획득 여부
        if(checkPermissions()) {
            Log.d(TAG, "success getting permissions");
            Toast.makeText(this, "모든 인증이 완료됨", Toast.LENGTH_LONG).show();
        }
        else {
            ActivityCompat.requestPermissions(this, REQUIRED_PERMISSIONS , REQUEST_PERMISSIONS_CODE);
        }

        textureView = findViewById(R.id.textureView);
        button = findViewById(R.id.button);
        zoomButton = findViewById(R.id.zoomButton);
        imageView = findViewById(R.id.imageView);

        // 텍스처 뷰 리스너 설정
        if(textureView != null)
            textureView.setSurfaceTextureListener(textureListener);

        // 촬영 버튼 클릭 이벤트 리스너
        if(button != null) {
            button.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    try {
                        Log.e(TAG, "take picture button clicked");
                        takePicture();
                    }
                    catch(CameraAccessException e) {
                        e.printStackTrace();
                    }
                }
            });
        }

        // 줌 버튼 클릭 이벤트 리스너
        if(zoomButton != null) {
            zoomButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Log.e(TAG, "zoom button clicked");
                    zoom();
                }
            });
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.e(TAG, "onResume");

        startBackgroundThread();

        if(textureView.isAvailable()) {
            try {
                openCamera();
            }
            catch(CameraAccessException e) {
                e.printStackTrace();
            }
        }
        else {
            textureView.setSurfaceTextureListener(textureListener);
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        try {
            stopBackgroundThread();
        }
        catch(InterruptedException e) {
            e.printStackTrace();
        }
    }

    private boolean checkPermissions() {
        for(String permission : REQUIRED_PERMISSIONS) {
            if(ContextCompat.checkSelfPermission(this, permission) != PackageManager.PERMISSION_GRANTED) {
                return false;
            }
        }
        return true;
    }

    // 카메라 오픈
    private void openCamera() throws CameraAccessException {

        CameraManager cameraManager = (CameraManager) getSystemService(Context.CAMERA_SERVICE);
        cameraId = cameraManager.getCameraIdList()[0];
        cameraCharacteristics = cameraManager.getCameraCharacteristics(cameraId);

        StreamConfigurationMap map = cameraCharacteristics.get(CameraCharacteristics.SCALER_STREAM_CONFIGURATION_MAP);

        maxZoom = (cameraCharacteristics.get(CameraCharacteristics.SCALER_AVAILABLE_MAX_DIGITAL_ZOOM));
        Log.e(TAG, "maxzoom " + maxZoom);
        sensorSize = cameraCharacteristics.get(CameraCharacteristics.SENSOR_INFO_ACTIVE_ARRAY_SIZE);

        // 이미지 사이즈 가져옴. (textureView에 뿌려질 이미지 해상도)
        imageSize = new Size(640, 480);
        for(Size size : map.getOutputSizes(SurfaceTexture.class)) {
            if(size.getWidth() == 1088 && size.getHeight() == 1088)
                imageSize = size;
        }
        Log.e(TAG, "" + imageSize);


        if(ActivityCompat.checkSelfPermission(this, "android.permission.CAMERA") == PackageManager.PERMISSION_GRANTED) {
            cameraManager.openCamera(cameraId, stateCallback, null);
        }
        else {
            ActivityCompat.requestPermissions(this, REQUIRED_PERMISSIONS, REQUEST_PERMISSIONS_CODE);
        }
    }

    private void createCameraPreview() throws CameraAccessException {
        SurfaceTexture texture = textureView.getSurfaceTexture();
        texture.setDefaultBufferSize(imageSize.getWidth(), imageSize.getHeight());
        Surface surface = new Surface(texture);

        imageReader = ImageReader.newInstance(imageSize.getWidth(), imageSize.getHeight(), ImageFormat.JPEG, 1);

        captureRequestBuilder = cameraDevice.createCaptureRequest(CameraDevice.TEMPLATE_PREVIEW);
        captureRequestBuilder.addTarget(surface);
        captureRequestBuilder.addTarget(imageReader.getSurface());

        cameraDevice.createCaptureSession(Arrays.asList(surface, imageReader.getSurface()), new CameraCaptureSession.StateCallback() {
            @Override
            public void onConfigured(@NonNull CameraCaptureSession session) {
                if(cameraDevice == null) {
                    return;
                }
                cameraCaptureSession = session;
                try {
                    updatePreview();
                }
                catch(CameraAccessException e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void onConfigureFailed(@NonNull CameraCaptureSession cameraCaptureSession) {
                Toast.makeText(getApplicationContext(), "Configuration Changed", Toast.LENGTH_LONG).show();
            }
        }, null);
    }

    private void updatePreview() throws CameraAccessException {
        if (cameraDevice == null) {
            Log.e(TAG, "cameraDevice is null");
            return;
        }

        // 줌
        int centerX = this.sensorSize.width() / 2;
        int centerY = this.sensorSize.height() / 2;
        int deltaX  = (int)((0.5f * this.sensorSize.width()) / nowZoom);
        int deltaY  = (int)((0.5f * this.sensorSize.height()) / nowZoom);

        cropRegion = new Rect();
        cropRegion.set(centerX - deltaX,
                centerY - deltaY,
                centerX + deltaY,
                centerY + deltaY);

        // 카메라로 부터 이미지 계속 받아옴
        // captureRequestBuilder.set(CaptureRequest.CONTROL_MODE, CameraMetadata.CONTROL_MODE_AUTO);
        captureRequestBuilder.set(CaptureRequest.SCALER_CROP_REGION, cropRegion);
        captureRequestBuilder.set(CaptureRequest.CONTROL_AE_TARGET_FPS_RANGE, new Range<>(10, 20));
        cameraCaptureSession.setRepeatingRequest(captureRequestBuilder.build(), null, backgroundHandler);
        imageReader.setOnImageAvailableListener(new ImageReader.OnImageAvailableListener() {
            @Override
            public void onImageAvailable(ImageReader imageReader) {
                Image image = imageReader.acquireLatestImage();
                ByteBuffer buffer = image.getPlanes()[0].getBuffer();
                byte[] bytes = new byte[buffer.capacity()];
                buffer.get(bytes);

                // 흑백으로 변환
                Bitmap bitmap = BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
                Mat matInput = new Mat();
                Utils.bitmapToMat(bitmap, matInput);
                Mat matResult = new Mat(matInput.rows(), matInput.cols(), matInput.type());

                ConvertRGBtoGray(matInput.getNativeObjAddr(), matResult.getNativeObjAddr());
                Utils.matToBitmap(matResult, bitmap);
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        imageView.setImageBitmap(bitmap);
                    }
                });

                Log.d(TAG, "width " + bitmap.getWidth() + " height " + bitmap.getHeight());
                if(image != null)
                    image.close();
            }
        }, imageHandler);
    }

    // 스레드
    protected void startBackgroundThread() {
        backgroundThread = new HandlerThread("camera background");
        backgroundThread.start();
        backgroundHandler = new Handler(backgroundThread.getLooper());

        imageThread = new HandlerThread("image handler");
        imageThread.start();
        imageHandler = new Handler(imageThread.getLooper());
    }

    protected void stopBackgroundThread() throws InterruptedException {
        backgroundThread.quitSafely();
        backgroundThread.join();
        backgroundThread = null;
        backgroundHandler = null;

        imageThread.quitSafely();
        imageThread.join();
        imageThread = null;
        imageHandler = null;
    }

    // 리스너
    private TextureView.SurfaceTextureListener textureListener = new TextureView.SurfaceTextureListener() {
        @Override
        public void onSurfaceTextureAvailable(@NonNull SurfaceTexture surface, int width, int height) {
            try {
                openCamera();
            } catch (CameraAccessException e) {
                e.printStackTrace();
            }
        }

        @Override
        public void onSurfaceTextureSizeChanged(@NonNull SurfaceTexture surface, int width, int height) {

        }

        @Override
        public boolean onSurfaceTextureDestroyed(@NonNull SurfaceTexture surface) {
            return false;
        }

        @Override
        public void onSurfaceTextureUpdated(@NonNull SurfaceTexture surface) {
        }
    };

    // 리스너
    private final CameraDevice.StateCallback stateCallback = new CameraDevice.StateCallback() {
        @Override
        public void onOpened(@NonNull CameraDevice camera) {
            Log.e(TAG, "camera onOpened");
            cameraDevice = camera;
            try {
                createCameraPreview();
            }
            catch(CameraAccessException e) {
                e.printStackTrace();
            }
        }

        @Override
        public void onDisconnected(@NonNull CameraDevice camera) {
            cameraDevice.close();
        }

        @Override
        public void onError(@NonNull CameraDevice camera, int i) {
            cameraDevice.close();
            cameraDevice = null;
        }
    };

    private void takePicture() throws CameraAccessException {
        if(cameraDevice == null) {
            Log.e(TAG, "cameraDevice is null");
            return;
        }

        // 카메라 매니저
        CameraManager manager = (CameraManager) getSystemService(Context.CAMERA_SERVICE);

        // 기본값, 이미지 해상도
        int width = 1088;
        int height = 1088;

        // 이미지
        ImageReader reader = ImageReader.newInstance(width, height, ImageFormat.JPEG, 1);
        List<Surface> outputSurfaces = new ArrayList<Surface>(2);

        // imageReader 에서 surface 객체 가져옴
        outputSurfaces.add(reader.getSurface());
        outputSurfaces.add(new Surface(textureView.getSurfaceTexture()));

        // request, 아마 응답? 이 오면 imageReader에 저장하는 것 같음.
        final CaptureRequest.Builder captureBuilder = cameraDevice.createCaptureRequest(CameraDevice.TEMPLATE_STILL_CAPTURE);
        captureBuilder.addTarget(reader.getSurface());
        // captureBuilder.set(CaptureRequest.CONTROL_MODE, CameraMetadata.CONTROL_MODE_AUTO);
        captureBuilder.set(CaptureRequest.SCALER_CROP_REGION, cropRegion);

        // 회전
        int rotation = getWindowManager().getDefaultDisplay().getRotation();
        captureBuilder.set(CaptureRequest.JPEG_ORIENTATION, ORIENTATIONS.get(rotation));

        // 저장
        File folder = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES).toString() + "/test");
        String path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES).toString() + "/test";
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String imageFileName = "IMG_" + timeStamp + ".jpg";
        file = new File(path, imageFileName);
        if(!folder.exists())
            folder.mkdir();

        ImageReader.OnImageAvailableListener readerListener = new ImageReader.OnImageAvailableListener() {
            @Override
            public void onImageAvailable(ImageReader imageReader) {
                Image image = null;

                // 카메라 이미지 가져오기
                image = imageReader.acquireLatestImage();
                ByteBuffer buffer = image.getPlanes()[0].getBuffer();
                byte[] bytes = new byte[buffer.capacity()];
                buffer.get(bytes);

                /*
                Bitmap bitmap = BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
                Mat matInput = new Mat();
                Utils.bitmapToMat(bitmap, matInput);
                Mat matResult = new Mat(matInput.rows(), matInput.cols(), matInput.type());

                흑백으로 변환
                ConvertRGBtoGray(matInput.getNativeObjAddr(), matResult.getNativeObjAddr());
                Utils.matToBitmap(matResult, bitmap);
                ByteArrayOutputStream stream = new ByteArrayOutputStream();
                bitmap.compress(Bitmap.CompressFormat.JPEG, 100, stream);
                byte[] byteArray = stream.toByteArray();
                */

                try {
                    save(bytes);
                    // 갤러리 갱신
                    sendBroadcast(new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE, Uri.fromFile(file)));
                }
                catch(IOException e) {
                    e.printStackTrace();
                }
                finally {
                    if(image != null)
                        image.close();
                }
            }
        };

        reader.setOnImageAvailableListener(readerListener, backgroundHandler);

        final CameraCaptureSession.CaptureCallback captureListener = new CameraCaptureSession.CaptureCallback() {
            @Override
            public void onCaptureCompleted(@NonNull CameraCaptureSession session, @NonNull CaptureRequest request, @NonNull TotalCaptureResult result) {
                super.onCaptureCompleted(session, request, result);
                try {
                    Log.d(TAG, "saved");
                    // 이게 없으면 찍고 난 이후 화면 새로고침이 되지 않음.
                    createCameraPreview();
                }
                catch(CameraAccessException e) {
                    e.printStackTrace();
                }
            }
        };

        cameraDevice.createCaptureSession(outputSurfaces, new CameraCaptureSession.StateCallback() {
            @Override
            public void onConfigured(@NonNull CameraCaptureSession cameraCaptureSession) {
                try {
                    cameraCaptureSession.capture(captureBuilder.build(), captureListener, backgroundHandler);
                }
                catch(CameraAccessException e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void onConfigureFailed(@NonNull CameraCaptureSession cameraCaptureSession) {

            }
        }, backgroundHandler);
    }

    public void zoom() {
        if( nowZoom == 1.0f) {
            nowZoom = 1.5f;
        }
        else {
            nowZoom = 1.0f;
        }

        try {
            updatePreview();
        }
        catch(CameraAccessException e) {
            e.printStackTrace();
        }

        Log.e(TAG, "nowZoom " + nowZoom);
    }

    private void save(byte[] bytes) throws IOException{
        OutputStream outputStream = null;
        outputStream = new FileOutputStream(file);
        outputStream.write(bytes);
        outputStream.close();
    }
}