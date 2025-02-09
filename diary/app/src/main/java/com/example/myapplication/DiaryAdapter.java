package com.example.myapplication;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.Collections;

public class DiaryAdapter extends RecyclerView.Adapter<DiaryAdapter.ViewHolder> {
    ArrayList<DiaryItem> items = new ArrayList<DiaryItem>();

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View itemView = inflater.inflate(R.layout.diary_cardview, parent, false);

        return new ViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        DiaryItem item = items.get(position);
        holder.setItem(item);
    }

    @Override
    public int getItemCount() {
        return items.size();
    }

    public void addItem(DiaryItem item) {
        items.add(item);
        Collections.sort(items);
    }

    public boolean checkExist(DiaryItem item) {
        for(DiaryItem i : items) {
            if(i.getId() == item.getId())
                return false;
        }
        return true;
    }

    public void clear() {
        items = new ArrayList<DiaryItem>();
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        TextView dateTextView, subjectTextView;

        public ViewHolder(View itemView) {
            super(itemView);

            dateTextView = itemView.findViewById(R.id.dateTextView);
            subjectTextView = itemView.findViewById(R.id.subjectTextView);
        }

        public void setItem(DiaryItem item) {
            dateTextView.setText(item.getDate());
            subjectTextView.setText(item.getTitle());
        }
    }
}
