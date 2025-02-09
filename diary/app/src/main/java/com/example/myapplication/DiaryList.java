package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.widget.LinearLayout;

public class DiaryList extends AppCompatActivity {

    DBHelper helper;
    SQLiteDatabase db;

    DiaryAdapter adapter = new DiaryAdapter();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_diary_list);

        RecyclerView recyclerView = findViewById(R.id.recyclerView);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        recyclerView.setLayoutManager(layoutManager);

        helper = new DBHelper(this, "diary.db", null, 1);
        db = helper.getWritableDatabase();

        dbSelect();
        recyclerView.setAdapter(adapter);
    }

    private void dbSelect() {
        String sql = "select * from diary;";
        Cursor cursor = db.rawQuery(sql, null);
        adapter.clear();

        while(cursor.moveToNext()) {
            int id = cursor.getInt(0);
            String subject = cursor.getString(1);
            String content = cursor.getString(2);
            String date = cursor.getString(3);
            DiaryItem item = new DiaryItem(id, subject, content, date);
            adapter.addItem(item);
        }
    }
}