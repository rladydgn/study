package tobyspring.hellospring.exrate;

import java.io.IOException;
import java.math.BigDecimal;
import java.net.URI;
import java.net.URISyntaxException;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import tobyspring.hellospring.api.ApiExecutor;
import tobyspring.hellospring.api.ExRateExtractor;
import tobyspring.hellospring.api.SimpleApiExecutor;
import tobyspring.hellospring.payment.ExRateProvider;

public class WebApiExRateProvider implements ExRateProvider {
	@Override
	public BigDecimal getExRate(String currency) {
		String url = "https://open.er-api.com/v6/latest/" + currency;

		// 콜백
		// runApiForExRate(url, uri -> {});
		return runApiForExRate(url, new SimpleApiExecutor(), response -> {
			ObjectMapper mapper = new ObjectMapper();
			ExRateDate data = mapper.readValue(response, ExRateDate.class);
			System.out.println("API ExRate: " + data.rates().get("KRW"));
			return data.rates().get("KRW");
		});
	}

	// 템플릿
	private static BigDecimal runApiForExRate(String url, ApiExecutor apiExecutor, ExRateExtractor exRateExtractor) {
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
