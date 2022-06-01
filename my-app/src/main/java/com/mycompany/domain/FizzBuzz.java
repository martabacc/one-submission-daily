package com.mycompany.domain;
import java.util.*;

public class FizzBuzz {
    public static String check(int number) {
        StringBuilder result = new StringBuilder();
        if(number % 3 == 0) {
            result.append("fizz");
        }
        if(number % 5 == 0) {
            result.append("buzz");
        }

        if(result.length() > 0) {
            return result.toString();
        }

        return Integer.toString(number);
    }
}