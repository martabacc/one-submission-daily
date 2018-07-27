package main

import "fmt"

func getFibonacci(sequence int) int {
	return sequence
}

func main() {
	number := 10
	fibonacciResult := getFibonacci(number);
	fmt.Println("Fibonacci for", number, "is", fibonacciResult)
}
