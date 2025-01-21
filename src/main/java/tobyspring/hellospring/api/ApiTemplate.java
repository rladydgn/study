package tobyspring.hellospring.api;

import java.io.IOException;
import java.math.BigDecimal;
import java.net.URI;
import java.net.URISyntaxException;

import com.fasterxml.jackson.core.JsonProcessingException;

public class ApiTemplate {
	private final ApiExecutor apiExecutor;
	private final ExRateExtractor exRateExtractor;

	public ApiTemplate() {
		this.apiExecutor = new HttpClientApiExecutor();
		this.exRateExtractor = new ErApiExRateExtractor();
	}

	public BigDecimal getForExRate(String url) {
		return getForExRate(url, apiExecutor, exRateExtractor);
	}

	public BigDecimal getForExRate(String url, ApiExecutor apiExecutor) {
		return getForExRate(url, apiExecutor, exRateExtractor);
	}

	public BigDecimal getForExRate(String url, ExRateExtractor exRateExtractor) {
		return getForExRate(url, apiExecutor, exRateExtractor);
	}

	public BigDecimal getForExRate(String url, ApiExecutor apiExecutor, ExRateExtractor exRateExtractor) {
		URI uri;
		try {
			uri = new URI(url);
		} catch (URISyntaxException e) {
			throw new RuntimeException(e);
		}

		String response;
		try {
			response = apiExecutor.execute(uri);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}

		try {
			return exRateExtractor.extract(response);
		} catch (JsonProcessingException e) {
			throw new RuntimeException(e);
		}
	}
}
