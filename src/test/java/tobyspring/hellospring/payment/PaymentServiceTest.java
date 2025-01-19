package tobyspring.hellospring.payment;

import static org.assertj.core.api.Assertions.*;

import java.io.IOException;
import java.math.BigDecimal;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class PaymentServiceTest {

	@Test
	@DisplayName("prepare 메서드가 요구사항 3가지를 잘 충족했는지 검증")
	void convertedAmount() throws IOException {
		testAmount(BigDecimal.valueOf(500), BigDecimal.valueOf(5000));
		testAmount(BigDecimal.valueOf(1000), BigDecimal.valueOf(10000));
		testAmount(BigDecimal.valueOf(3000), BigDecimal.valueOf(30000));
		// 원화 환산 금액 유효시간 계산
		// assertThat(payment.getValidUntil()).isAfter(LocalDateTime.now());
		// assertThat(payment.getValidUntil()).isBefore(LocalDateTime.now().plusMinutes(30));
	}

	private static void testAmount(BigDecimal exRate, BigDecimal convertedAmount) throws IOException {
		PaymentService paymentService = new PaymentService(new ExRateProviderStub(exRate));

		Payment payment = paymentService.prepare(1L, "USD", BigDecimal.TEN);

		// 환율정보 가져오기
		assertThat(payment.getExRate()).isEqualTo(exRate);
		// 원화 환산 금액 계산
		assertThat(payment.getConvertedAmount()).isEqualTo(convertedAmount);
	}
}
