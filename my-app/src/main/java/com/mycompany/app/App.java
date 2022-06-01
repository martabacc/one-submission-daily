package com.mycompany.app;

import java.util.Scanner;
import com.mycompany.domain.FizzBuzz;

public class App
{
    public static void main( String[] args )
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Til which number you want fizzbuzz to be printed: ");
        int number = input.nextInt();

        input.close();

        App.printFizzBuzzTilNumber(number);
    }

    public static void printFizzBuzzTilNumber(int limit) {
        FizzBuzz logic = new FizzBuzz();
        for (int i=1;i<=limit;i++) {
            System.out.print(FizzBuzz.check(i)+ " ");
        }

        System.out.print("\n");
    }

    public static String getGreeting() {
        return "Hello world!";
    }
}
