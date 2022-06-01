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
    void shouldReturnStringifiedNumber()
    {
        int input = 4;
        String actual = FizzBuzz.check(input);
        String expected = "4";

        assertEquals(actual, expected);
    }
    @Test
    @DisplayName("it should return fizz when divisible by 3")
    void shouldReturnFizz()
    {
        int input = 3;
        String actual = FizzBuzz.check(input);
        String expected = "fizz";

        assertEquals(actual, expected);
    }
    @Test
    @DisplayName("it should return buzz when divisible by 5")
    void shouldReturnBuzz()
    {
        int input = 5;
        String actual = FizzBuzz.check(input);
        String expected = "buzz";

        assertEquals(actual, expected);
    }
    @Test
    @DisplayName("it should return fizzbuzz when divisible by 15")
    void shouldReturnFizzBuzz()
    {
        int input = 45;
        String actual = FizzBuzz.check(input);
        String expected = "fizzbuzz";

        assertEquals(actual, expected);
    }
}
