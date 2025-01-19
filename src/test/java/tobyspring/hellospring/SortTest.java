package tobyspring.hellospring;

import java.util.Arrays;
import java.util.List;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

public class SortTest {
	@Test
	void sort() {
		// 준비 (given)
		Sort sort = new Sort();

		// 실행 (when)
		// List.of 는 변경 불가능한 리스트 임
		List<String> list = sort.sortByLength(Arrays.asList("aa", "b"));

		// 검증 (then)
		Assertions.assertThat(list).isEqualTo(List.of("b", "aa"));
	}
}
