package org.example.chapter3;

import java.io.BufferedReader;
import java.io.FileReader;

public class Main {

	public static String processFile(CustomFileReader customFileReader) {
		try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/test.txt"))) {
			return customFileReader.process(br);
		} catch (Exception e) {
			return e.toString();
		}
	}

	public static void main(String[] args) {
		System.out.println(processFile(new FileReaderImpl()));
	}
}
