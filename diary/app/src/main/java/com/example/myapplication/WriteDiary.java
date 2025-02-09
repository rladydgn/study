package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class WriteDiary extends AppCompatActivity {

    DBHelper helper;
    SQLiteDatabase db;

    EditText subjectText, contentText;
    TextView textView;

    Intent intent;
    boolean dbExist = false;
    String year, month, day;
    String s[];

    static final String TAG = "WriteDiary";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_write_diary);

        helper = new DBHelper(this, "diary.db", null, 1);
        db = helper.getWritableDatabase();
        helper.onCreate(db);

        subjectText = findViewById(R.id.subjectText);
        contentText = findViewById(R.id.contentText);
        textView = findViewById(R.id.textView);

        intent = getIntent();
        year = intent.getStringExtra("year");
        month = intent.getStringExtra("month");
        day = intent.getStringExtra("day");
        textView.setText(year + "년 " + month + "월 " + day + "일 ");

        s = dbSelect();
    }

    public void onButton2Clicked(View v) {
        Log.d(TAG, "button Clicked");
        if(subjectText.getText().toString().equals("") || contentText.getText().toString().equals("")) {
            Toast.makeText(this, "제목 또는 내용을 적어주세요.", Toast.LENGTH_LONG).show();
            return;
        }
        ContentValues values = new ContentValues();
        values.put("subject", subjectText.getText().toString());
        values.put("content", contentText.getText().toString());
        String date = intent.getStringExtra("year") + intent.getStringExtra("month") +
                intent.getStringExtra("day");
        values.put("date", date);
        if(s[0] == "yes") {
            db.update("diary", values, "_id = ?", new String[] {s[1]});
            Toast.makeText(this, "성공적으로 업데이트 되었습니다.", Toast.LENGTH_LONG).show();
        }
        else {
            db.insert("diary", null, values);
            Toast.makeText(this, "성공적으로 저장되었습니다.", Toast.LENGTH_LONG).show();
        }
        Log.d(TAG, "WriteDiary: " + date);
        finish();
    }

    private String[] dbSelect() {
        Log.d(TAG, "dbSelect() called.");
        if(month.length() == 1)
            month = "0" + month;
        if(day.length() == 1)
            day = "0" + day;
        String d = year + month + day;
        Log.d(TAG, "MainActivity: " + d);
        String sql = "select * from diary where date=" + d + ";";
        Cursor cursor = db.rawQuery(sql, null);
        // 이미 쓴 일기가 존재할 경우
        String s[] = new String[5];
        if(cursor.moveToNext()) {
            Log.d(TAG, "exist");
            s[0] = "yes";
            s[1] = Integer.toString(cursor.getInt(0));
            s[2] = cursor.getString(1);
            s[3] = cursor.getString(2);
            s[4] = cursor.getString(3);
            subjectText.setText(s[2]);
            contentText.setText(s[3]);
        }
        // 존재하지 않을경우
        else
            s[0] = "no";

        return s;
    }

    private void dbUpdate(String s[]) {
    }

    private boolean checkExist(String s) {
        if(s == "yes")
            return true;
        return false;
    }
}