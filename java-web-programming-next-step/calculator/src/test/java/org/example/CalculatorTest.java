package org.example;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class CalculatorTest {

    private static Calculator calculator;
    private static String[] inputs = {"", "1", "1,2,3", "1:2:3", "//.\n1.2.3"};
    private static int[] expects = {0, 1, 6, 6, 6};

    @BeforeAll
    static public void setup() {
        calculator = new Calculator();
    }
    @Test
    void calculate() {
        for (int i = 0; i < inputs.length; i++) {
            assertEquals(expects[i], calculator.calculate(inputs[i]));
        }
    }

    @Test()
    void calculate_음수() {
        assertThrows(RuntimeException.class, () -> {
            calculator.calculate("1,-1,2");
        });
    }
}