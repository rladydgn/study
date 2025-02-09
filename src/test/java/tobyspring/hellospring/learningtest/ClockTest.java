package tobyspring.hellospring.learningtest;

import java.time.Clock;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

public class ClockTest {
	// Clock 을 이용해서 LocalDateTime.now
	@Test
	void clock() {
		Clock clock = Clock.systemDefaultZone();
		LocalDateTime dt1 = LocalDateTime.now(clock);
		LocalDateTime dt2 = LocalDateTime.now(clock);

		// 계속 이동하는 시간이라는 것을 알 수 있다.
		Assertions.assertThat(dt2).isAfter(dt1);
	}

	// CLock 을 Test 에서 사용할 때 내가 원하는 시간을 지졍서 현재 시간을 가져오는게 가능한가?
	@Test
	void fixedClock() {
		// 고정된 시간
		Clock clock = Clock.fixed(Instant.now(), ZoneId.systemDefault());
		LocalDateTime dt1 = LocalDateTime.now(clock);
		LocalDateTime dt2 = LocalDateTime.now(clock);

		Assertions.assertThat(dt2).isEqualTo(dt1);
	}
}
