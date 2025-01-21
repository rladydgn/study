package tobyspring.hellospring;

import java.time.Clock;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.client.JdkClientHttpRequestFactory;
import org.springframework.web.client.RestTemplate;

import tobyspring.hellospring.api.ApiTemplate;
import tobyspring.hellospring.api.ErApiExRateExtractor;
import tobyspring.hellospring.api.SimpleApiExecutor;
import tobyspring.hellospring.exrate.CachedExRateProvider;
import tobyspring.hellospring.exrate.RestTemplateExRateProvider;
import tobyspring.hellospring.exrate.WebApiExRateProvider;
import tobyspring.hellospring.payment.ExRateProvider;
import tobyspring.hellospring.payment.PaymentService;

@Configuration
public class PaymentConfig {
	@Bean
	public PaymentService paymentService() {
		return new PaymentService(cachedExRateProvider(), clock());
	}

	@Bean
	public ExRateProvider cachedExRateProvider() {
		return new CachedExRateProvider(exRateProvider());
	}

	@Bean
	public ExRateProvider exRateProvider() {
		return new RestTemplateExRateProvider(restTemplate());
	}

	@Bean
	public Clock clock() {
		return Clock.systemDefaultZone();
	}

	@Bean
	public RestTemplate restTemplate() {
		// 생성자에서 전략을 직접 넣어줄 수 있다.
		// return new RestTemplate();
		return new RestTemplate(new JdkClientHttpRequestFactory());
	}
}
