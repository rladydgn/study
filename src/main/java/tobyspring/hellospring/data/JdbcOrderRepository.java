package tobyspring.hellospring.data;

import javax.sql.DataSource;

import org.springframework.jdbc.core.simple.JdbcClient;

import jakarta.annotation.PostConstruct;
import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import tobyspring.hellospring.order.Order;

public class JdbcOrderRepository implements tobyspring.hellospring.order.OrderRepository {
	private final JdbcClient jdbcClient;

	public JdbcOrderRepository(DataSource dataSource) {
		this.jdbcClient = JdbcClient.create(dataSource);
	}

	@PostConstruct
	void initDb() {
		jdbcClient.sql("""
			create table orders (id bigint not null, orderNumber varchar(255), total numeric(38,2), primary key (id));
			alter table if exists orders drop constraint if exists UKt5ee3vjmonruwsp9g423dhrek;
			alter table if exists orders add constraint UKt5ee3vjmonruwsp9g423dhrek unique (orderNumber);
			create sequence orders_SEQ start with 1 increment by 50;
		""").update();
	}

	@Override
	public void save(Order order) {
		Long id = jdbcClient.sql("select next value for orders_SEQ")
			.query(Long.class)
			.single();

		System.out.println(id);
	}
}
