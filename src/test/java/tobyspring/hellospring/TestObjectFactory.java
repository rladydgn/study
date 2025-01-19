package tobyspring.hellospring;

import java.math.BigDecimal;

import org.springframework.context.annotation.Bean;

import tobyspring.hellospring.payment.ExRateProvider;
import tobyspring.hellospring.payment.ExRateProviderStub;
import tobyspring.hellospring.payment.PaymentService;

public class TestObjectFactory {
	@Bean
	public PaymentService paymentService() {
		return new PaymentService(exRateProvider());
	}

	@Bean
	public ExRateProvider exRateProvider() {
		return new ExRateProviderStub(BigDecimal.valueOf(1000));
	}
}
