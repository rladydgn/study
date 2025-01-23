package tobyspring.hellospring.data;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import tobyspring.hellospring.order.Order;

public class JpaOrderRepository implements tobyspring.hellospring.order.OrderRepository {
	@PersistenceContext
	private EntityManager entityManager;

	@Override
	public void save(Order order) {
		entityManager.persist(order);

	}
}
