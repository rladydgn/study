var uploadBox = document.getElementById("filebox");
var uploadName = document.getElementById("upload-name");

/* 박스 안에 Drag 들어왔을 때 */
uploadBox.addEventListener('dragenter', function(e) {
    console.log('dragenter');
});

/* 박스 안에 Drag를 하고 있을 때 */
uploadBox.addEventListener('dragover', function(e) {
    e.preventDefault();
    console.log('dragover');

    this.style.backgroundColor = 'gray';
});

/* 박스 밖으로 Drag가 나갈 때 */
uploadBox.addEventListener('dragleave', function(e) {
    console.log('dragleave');

    this.style.backgroundColor = 'lightgray';
});

/* 박스 안에서 Drag를 Drop했을 때 */
uploadBox.addEventListener('drop', function(e) {
    e.preventDefault();

    // console.log('drop');
    this.style.backgroundColor = 'lightgray';

    // console.dir(e.dataTransfer);

    var data = e.dataTransfer.files[0];
    if(e.dataTransfer.files.length != 1) {
        alert("반드시 하나의 파일만 넣어주세요.");
        return;
    }
    // console.dir(data);
    uploadName.files = e.dataTransfer.files;
    // console.log(uploadName.files);
});