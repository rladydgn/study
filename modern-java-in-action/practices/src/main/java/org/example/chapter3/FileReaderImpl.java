package org.example.chapter3;

import java.io.BufferedReader;
import java.io.IOException;

public class FileReaderImpl implements CustomFileReader {
	@Override
	public String process(BufferedReader br) throws IOException {
		return br.readLine() + br.readLine();
	}
}
