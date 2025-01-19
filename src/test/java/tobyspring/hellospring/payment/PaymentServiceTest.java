package tobyspring.hellospring.payment;

import static org.assertj.core.api.Assertions.*;

import java.io.IOException;
import java.math.BigDecimal;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.BeanFactory;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import tobyspring.hellospring.TestObjectFactory;

class PaymentServiceTest {

	@Test
	@DisplayName("prepare 메서드가 요구사항 3가지를 잘 충족했는지 검증")
	void convertedAmount() throws IOException {
		BeanFactory beanFactory = new AnnotationConfigApplicationContext(TestObjectFactory.class);
		PaymentService paymentService = beanFactory.getBean(PaymentService.class);

		Payment payment = paymentService.prepare(1L, "USD", BigDecimal.TEN);

		// 환율정보 가져오기
		assertThat(payment.getExRate()).isEqualByComparingTo(BigDecimal.valueOf(1000));
		// 원화 환산 금액 계산
		assertThat(payment.getConvertedAmount()).isEqualByComparingTo(BigDecimal.valueOf(10000));
		// 원화 환산 금액 유효시간 계산
		// assertThat(payment.getValidUntil()).isAfter(LocalDateTime.now());
		// assertThat(payment.getValidUntil()).isBefore(LocalDateTime.now().plusMinutes(30));
	}
}
