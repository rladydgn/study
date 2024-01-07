package org.example;

import java.util.Scanner;

public class Main {
    static boolean isInputNullOrEmpty(String input) {
        if(input == null || input.isEmpty()) return true;
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        Calculator calculator = new Calculator();
        System.out.println(calculator.calculate(input));
    }
}