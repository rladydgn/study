package tobyspring.hellospring;

import java.math.BigDecimal;
import java.util.Map;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public record ExRateDate(String result, Map<String, BigDecimal> rates) {
}
