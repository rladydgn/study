package tobyspring.hellospring.order;

import java.math.BigDecimal;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name = "orders")
public class Order {
	@Id
	@GeneratedValue
	private Long id;
	@Column(unique = true)
	private String orderNumber;
	private BigDecimal total;

	public Order(String orderNumber, BigDecimal total) {
		this.orderNumber = orderNumber;
		this.total = total;
	}

	@Override
	public String toString() {
		return "Order{" +
			"id=" + id +
			", orderNumber='" + orderNumber + '\'' +
			", total=" + total +
			'}';
	}

	public Long getId() {
		return id;
	}

	public String getOrderNumber() {
		return orderNumber;
	}

	public BigDecimal getTotal() {
		return total;
	}
}
