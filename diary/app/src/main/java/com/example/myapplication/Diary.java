package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class Diary extends AppCompatActivity {

    TextView textView, textView2, textView3;

    DBHelper helper;
    SQLiteDatabase db;

    String year, month, day;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_diary);

        helper = new DBHelper(this, "diary.db", null, 1);
        db = helper.getWritableDatabase();

        textView = findViewById(R.id.textView2);
        textView2 = findViewById(R.id.textView3);
        textView3 = findViewById(R.id.textView4);

        Intent intent = getIntent();
        year = intent.getStringExtra("year");
        month = intent.getStringExtra("month");
        day = intent.getStringExtra("day");
        textView.setText(year + "년 " + month + "월 " + day + "일");
        textView2.setText("제목 : " + intent.getStringExtra("subject"));
        textView3.setText("내용 : " + intent.getStringExtra("content"));
    }

    public void onDeleteButtonClicked(View view) {
        db.execSQL("DELETE FROM diary where date=" + year + month + day);
        Toast.makeText(this, "삭제완료되었습니다.", Toast.LENGTH_LONG).show();
        finish();
    }

    public void onFixButtonClicked(View view) {
        Intent intent = new Intent(this, WriteDiary.class);
        intent.putExtra("year", year);
        intent.putExtra("month", month);
        intent.putExtra("day", day);
        startActivity(intent);
        finish();
    }
}