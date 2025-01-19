package tobyspring.hellospring.payment;

import static org.assertj.core.api.Assertions.*;

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
		PaymentService paymentService = new PaymentService(new ExRateProviderStub(BigDecimal.valueOf(500)));

		Payment payment = paymentService.prepare(1L, "USD", BigDecimal.TEN);

		// 환율정보 가져오기
		assertThat(payment.getExRate()).isEqualTo(BigDecimal.valueOf(500));
		// 원화 환산 금액 계산
		assertThat(payment.getConvertedAmount())
			.isEqualByComparingTo(BigDecimal.valueOf(5000));
		// 원화 환산 금액 유효시간 계산
		assertThat(payment.getValidUntil()).isAfter(LocalDateTime.now());
		assertThat(payment.getValidUntil()).isBefore(LocalDateTime.now().plusMinutes(30));
	}
}
