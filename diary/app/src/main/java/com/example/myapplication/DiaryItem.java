package com.example.myapplication;

public class DiaryItem implements Comparable<DiaryItem>{
    String date, title, content;
    int id;

    public DiaryItem(int id, String title, String content, String date) {
        this.date = date;
        this.title = title;
        this.content = content;
        this.id = id;
    }

    @Override
    public int compareTo(DiaryItem diaryItem) {
        if(Integer.parseInt(diaryItem.getDate()) > Integer.parseInt(date))
            return 1;
        else if(Integer.parseInt(diaryItem.getDate()) < Integer.parseInt(date))
            return -1;
        return 0;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
