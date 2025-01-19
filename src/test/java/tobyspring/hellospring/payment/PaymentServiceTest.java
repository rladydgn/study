package tobyspring.hellospring.payment;

import java.io.IOException;
import java.math.BigDecimal;
import java.time.LocalDateTime;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import tobyspring.hellospring.exrate.WebApiExRateProvider;

class PaymentServiceTest {

	@Test
	@DisplayName("prepare 메서드가 요구사항 3가지를 잘 충족했는지 검증")
	void prepare() throws IOException {
		PaymentService paymentService = new PaymentService(new WebApiExRateProvider());

		Payment payment = paymentService.prepare(1L, "USD", BigDecimal.TEN);

		// 환율정보 가져오기
		Assertions.assertThat(payment.getExRate()).isNotNull();
		// 원화 환산 금액 계산
		Assertions.assertThat(payment.getConvertedAmount())
			.isEqualByComparingTo(payment.getExRate().multiply(payment.getForeignCurrencyAmount()));
		// 원화 환산 금액 유효시간 계산
		Assertions.assertThat(payment.getValidUntil()).isAfter(LocalDateTime.now());
		Assertions.assertThat(payment.getValidUntil()).isBefore(LocalDateTime.now().plusMinutes(30));
	}
}
