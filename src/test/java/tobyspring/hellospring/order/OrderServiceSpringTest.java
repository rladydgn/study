package tobyspring.hellospring.order;

import java.math.BigDecimal;
import java.util.List;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import tobyspring.hellospring.OrderConfig;

@ExtendWith(SpringExtension.class)
@ContextConfiguration(classes = OrderConfig.class)
public class OrderServiceSpringTest {
	@Autowired
	OrderService orderService;

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
}
