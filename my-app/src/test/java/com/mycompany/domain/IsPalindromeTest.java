package com.mycompany.app;

import static org.junit.Assert.assertEquals;
import com.mycompany.domain.IsPalindrome;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for simple App.
 */
public class IsPalindromeTest
{
    @Test
    @DisplayName("it should return true if only 1 char sent")
    void shouldReturnTrueWhenOnlySingleCharSent()
    {
        String input = "A";
        boolean actual = IsPalindrome.check(input);
        boolean expected = true;

        assertEquals(actual, expected);
    }

    @Test
    @DisplayName("it should return true if only 2 identical char sent")
    void shouldReturnTrueOnAA()
    {
        String input = "AA";
        boolean actual = IsPalindrome.check(input);
        boolean expected = true;

        assertEquals(actual, expected);
    }

    @Test
    @DisplayName("it should return true if only 2 nonidentical char sent")
    void shouldReturnFalseOnAB()
    {
        String input = "AB";
        boolean actual = IsPalindrome.check(input);
        boolean expected = false;

        assertEquals(actual, expected);
    }

    @Test
    @DisplayName("it should return true for ABBA")
    void shouldReturnTrueOnABBA()
    {
        String input = "ABBA";
        boolean actual = IsPalindrome.check(input);
        boolean expected = true;

        assertEquals(actual, expected);
    }
}
