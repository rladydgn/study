package tobyspring.hellospring.exrate;

import java.math.BigDecimal;

import tobyspring.hellospring.api.ApiTemplate;
import tobyspring.hellospring.api.ErApiExRateExtractor;
import tobyspring.hellospring.api.SimpleApiExecutor;
import tobyspring.hellospring.payment.ExRateProvider;

public class WebApiExRateProvider implements ExRateProvider {
	@Override
	public BigDecimal getExRate(String currency) {
		ApiTemplate apiTemplate = new ApiTemplate();
		String url = "https://open.er-api.com/v6/latest/" + currency;

		// 콜백
		return apiTemplate.getExRate(url, new SimpleApiExecutor(), new ErApiExRateExtractor());
	}
}
