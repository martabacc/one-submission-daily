package main

import "fmt"

func getFibonacci(sequence int) int {
	if sequence == 1 || sequence == 2{
		return 1
	}

	return getFibonacci(sequence-1) + getFibonacci(sequence-2)
}

func main() {
	number := 10
	fibonacciResult := getFibonacci(number);
	fmt.Println("Fibonacci for", number, "is", fibonacciResult)
}
