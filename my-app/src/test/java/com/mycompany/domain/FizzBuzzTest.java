package com.mycompany.app;

import static org.junit.Assert.assertEquals;
import com.mycompany.domain.FizzBuzz;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for simple App.
 */
public class FizzBuzzTest
{
    @Test
    @DisplayName("it should return number when not divisible by 3")
    void shouldAnswerWithTrue()
    {
        int input = 4;
        String actual = FizzBuzz.check(input);
        String expected = "4";

        assertEquals(actual, expected);
    }
}
