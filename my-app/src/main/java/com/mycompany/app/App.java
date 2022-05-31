package com.mycompany.app;

/**
 * Hello world!
 *
 */
public class App
{
    public static void main( String[] args )
    {
        String greeting = App.getGreeting();
        System.out.println(greeting);
    }

    public static String getGreeting() {
        return "Hello world!";
    }
}
