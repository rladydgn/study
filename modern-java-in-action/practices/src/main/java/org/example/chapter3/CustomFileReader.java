package org.example.chapter3;

import java.io.BufferedReader;
import java.io.IOException;

@FunctionalInterface
public interface CustomFileReader {
	String process(BufferedReader br) throws IOException;
}
