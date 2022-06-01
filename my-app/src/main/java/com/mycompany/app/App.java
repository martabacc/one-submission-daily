package com.mycompany.app;

import java.util.*;
import com.mycompany.domain.IsPalindrome;

public class App
{
    public static void main( String[] args )
    {
        Scanner scanner = new Scanner(System.in);
        String result;

        while(true) {
            System.out.println("Input text to check, EXIT to exit");
            String input = scanner.nextLine();

            if (input.equals("EXIT")) {
                break;
            }

            result = IsPalindrome.check(input)
                ? "IS PALINDROME"
                : "NOT PALINDROME";

            System.out.println(result);
        }

        System.out.println("Exiting ...");
        scanner.close();
    }

    public static String getGreeting() {
        return "Hello world!";
    }
}
