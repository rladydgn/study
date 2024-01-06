package org.example;

import java.util.ArrayList;

public class Calculator {
    ArrayList<String> delimiters;
    String rawInput;
    String extractedCustomDelimiterInput;
    Calculator(String input) {
        delimiters = new ArrayList<>();
        delimiters.add(",");
        delimiters.add(":");
        this.rawInput = input;
        extractCustomDelimiter();
    }

    void extractCustomDelimiter() {
        if(isCustomDelimiter(rawInput)) {
            delimiters.add(Character.toString(rawInput.charAt(2)));
            extractedCustomDelimiterInput = rawInput.substring(5);
            return;
        }
        extractedCustomDelimiterInput = rawInput;
    }

    boolean isCustomDelimiter(String rawPrefix) {
        if(rawPrefix.substring(0, 2).equals("//") && rawPrefix.substring(3, 5).equals("\\n")) return true;
        return false;
    }

    public int calculate() {
        String delimiterRegex = createRegex();
        String[] values = extractedCustomDelimiterInput.split(delimiterRegex);
        int sum = 0;
        for(String stringValue: values) {
            int value = Integer.parseInt(stringValue);
            if(value < 0) throw new RuntimeException("음수는 계산할 수 없습니다.");
            sum += value;
        }
        return sum;
    }

    String createRegex() {
        String delimiterRegex = "[";
        for(String customDelimiter: this.delimiters) delimiterRegex += customDelimiter;
        delimiterRegex += "]";
        return delimiterRegex;
    }
}
