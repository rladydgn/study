package tobyspring.hellospring.payment;

import static org.assertj.core.api.Assertions.*;

import java.io.IOException;
import java.math.BigDecimal;
import java.time.Clock;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import tobyspring.hellospring.TestPaymentConfig;

@ExtendWith(SpringExtension.class)
@ContextConfiguration(classes = TestPaymentConfig.class)
class PaymentServiceTest {

	@Autowired
	PaymentService paymentService;
	@Autowired
	ExRateProviderStub exRateProviderStub;

	@Test
	@DisplayName("prepare 메서드가 요구사항 3가지를 잘 충족했는지 검증")
	void convertedAmount() throws IOException {
		Payment payment = paymentService.prepare(1L, "USD", BigDecimal.TEN);

		// 환율정보 가져오기
		assertThat(payment.getExRate()).isEqualByComparingTo(BigDecimal.valueOf(1000));
		// 원화 환산 금액 계산
		assertThat(payment.getConvertedAmount()).isEqualByComparingTo(BigDecimal.valueOf(10000));

		// exrate: 500
		exRateProviderStub.setExRate(BigDecimal.valueOf(500));
		Payment payment2 = paymentService.prepare(1L, "USD", BigDecimal.TEN);
		// 환율정보 가져오기
		assertThat(payment2.getExRate()).isEqualByComparingTo(BigDecimal.valueOf(500));
		// 원화 환산 금액 계산
		assertThat(payment2.getConvertedAmount()).isEqualByComparingTo(BigDecimal.valueOf(5000));

	}

	@Test
	@DisplayName("원화 환산 금액 유효시간 계산")
	void validUntil() throws IOException {
		Clock clock = Clock.fixed(Instant.now(), ZoneId.systemDefault());
		PaymentService paymentService1 = new PaymentService(exRateProviderStub, clock);
		Payment payment = paymentService1.prepare(1L, "USD", BigDecimal.TEN);

		LocalDateTime now = LocalDateTime.now(clock);
		LocalDateTime expectedValidUntil = now.plusMinutes(30);
		assertThat(payment.getValidUntil()).isEqualTo(expectedValidUntil);
	}
}
