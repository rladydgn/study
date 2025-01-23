package tobyspring.hellospring.order;

import java.math.BigDecimal;
import java.util.List;

import javax.sql.DataSource;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import tobyspring.hellospring.OrderConfig;

@ExtendWith(SpringExtension.class)
@ContextConfiguration(classes = OrderConfig.class)
public class OrderServiceSpringTest {
	@Autowired
	OrderService orderService;
	@Autowired
	DataSource dataSource;

	@Test
	void createOrder() {
		Order order = orderService.createOrder("0100", BigDecimal.ONE);

		Assertions.assertThat(order.getId()).isGreaterThan(0);
	}

	@Test
	void createOrders() {
		List<OrderReq> orderReqs = List.of(
			new OrderReq("0200", BigDecimal.ONE),
			new OrderReq("0300", BigDecimal.ONE)
		);

		List<Order> orders = orderService.createOrders(orderReqs);

		Assertions.assertThat(orders).hasSize(2);
		orders.forEach(order -> Assertions.assertThat(order.getId()).isGreaterThan(0));
	}

	@Test
	void createDuplicatedOrders() {
		List<OrderReq> orderReqs = List.of(
			new OrderReq("0200", BigDecimal.ONE),
			new OrderReq("0200", BigDecimal.ONE)
		);

		// 예외가 발생하면 성공하는 테스트
		Assertions.assertThatThrownBy(() -> orderService.createOrders(orderReqs)).
			isInstanceOf(DataIntegrityViolationException.class);

		// 예외 발생시 롤백 되었는지 확인
		JdbcClient client = JdbcClient.create(dataSource);
		Long count = client.sql("select count(*) from orders where orderNumber = '0200'").query(Long.class).single();
		Assertions.assertThat(count).isEqualTo(0);
	}
}
