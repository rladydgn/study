package tobyspring.hellospring.api;

import java.math.BigDecimal;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import tobyspring.hellospring.exrate.ExRateDate;

public class ErApiExRateExtractor implements ExRateExtractor {
	@Override
	public BigDecimal extract(String response) throws JsonProcessingException {
		ObjectMapper mapper = new ObjectMapper();
		ExRateDate data = mapper.readValue(response, ExRateDate.class);
		System.out.println("API ExRate: " + data.rates().get("KRW"));
		return data.rates().get("KRW");
	}
}
