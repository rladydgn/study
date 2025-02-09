package org.example;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Calculator {
    ArrayList<String> delimiters;
    String extractedCustomDelimiterInput;
    Calculator() {
        delimiters = new ArrayList<>();
        delimiters.add(",");
        delimiters.add(":");
    }

    private void extractCustomDelimiter(String input) {
        Matcher matcher = Pattern.compile("//(.)\n(.*)").matcher(input);
        if(matcher.find()) {
            delimiters.add(matcher.group(1));
            extractedCustomDelimiterInput = matcher.group(2);
            return;
        }
        extractedCustomDelimiterInput = input;
    }

    public int calculate(String input) {
        if(isInputNullOrEmpty(input)) return 0;

        extractCustomDelimiter(input);

        String delimiterRegex = createSplitRegex();
        String[] values = extractedCustomDelimiterInput.split(delimiterRegex);
        int sum = 0;

        for(String stringValue: values) {
            int value = Integer.parseInt(stringValue);
            if(value < 0) throw new RuntimeException("음수는 계산할 수 없습니다.");
            sum += value;
        }
        return sum;
    }

    private String createSplitRegex() {
        String delimiterRegex = "[";
        for(String customDelimiter: this.delimiters) delimiterRegex += customDelimiter;
        delimiterRegex += "]";
        return delimiterRegex;
    }

    static boolean isInputNullOrEmpty(String input) {
        if(input == null || input.isEmpty()) return true;
        return false;
    }
}
