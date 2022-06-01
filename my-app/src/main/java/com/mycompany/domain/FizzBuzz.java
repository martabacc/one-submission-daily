package com.mycompany.domain;

public class FizzBuzz {
    public static String check(int number) {
        if(number % 3 == 0) {
            return "fizz";
        }

        return Integer.toString(number);
    }
}