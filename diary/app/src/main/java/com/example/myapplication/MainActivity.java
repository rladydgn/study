package com.example.myapplication;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.CalendarView;
import android.widget.Toast;

import java.util.Calendar;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    CalendarView calendarView;
    Date date;

    DBHelper helper;
    SQLiteDatabase db;

    String year, month, day;

    static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        helper = new DBHelper(this, "diary.db", null, 1);
        db = helper.getWritableDatabase();
        helper.onCreate(db);

        Calendar calendar = Calendar.getInstance();
        calendarView = findViewById(R.id.calendarView);
        date = new Date(calendarView.getDate());
        calendar.setTime(date);

        year = Integer.toString(calendar.get(Calendar.YEAR));
        month = Integer.toString(calendar.get(Calendar.MONTH)+1);
        day = Integer.toString(calendar.get(Calendar.DATE));
        Log.d("t", "date: " + year + " " + month + " " + day);

        calendarView.setOnDateChangeListener(new CalendarView.OnDateChangeListener() {
            @Override
            public void onSelectedDayChange(@NonNull CalendarView calendarView, int i, int i1, int i2) {
                year = Integer.toString(i);
                month = Integer.toString(i1+1);
                day = Integer.toString(i2);
                Log.d("t", "date: " + year + " " + month + " " + day);
            }
        });
    }

    public void onButtonClicked(View v) {
        // 이미 쓴 일기가 존재할 경우
        String s[] = dbSelect();
        Intent intent;
        if(s[0].equals("yes")) {
            intent = new Intent(this, Diary.class);
            intent.putExtra("subject", s[1]);
            intent.putExtra("content", s[2]);
        }
        // 일기가 존재하지 않을 경우
        else {
            intent = new Intent(this, WriteDiary.class);
        }
        intent.putExtra("year", year);
        intent.putExtra("month" , month);
        intent.putExtra("day", day);

        startActivity(intent);
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
        String s[] = new String[3];
        if(cursor.moveToNext()) {
            Log.d(TAG, "exist");
            s[0] = "yes";
            s[1] = cursor.getString(1);
            s[2] = cursor.getString(2);
        }
        // 존재하지 않을경우
        else
            s[0] = "no";
        return s;
    }

    public void onRecyclerViewButtonClicked(View v) {
        Intent intent = new Intent(this, DiaryList.class);
        startActivity(intent);
    }


}