package com.mycompany.app;

import static org.junit.Assert.assertEquals;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for simple App.
 */
public class AppTest
{
    @Test
    void shouldAnswerWithTrue()
    {
        String actual = App.getGreeting();
        String expected = "Hello world!";

        assertEquals(actual, expected);
    }
}
