package main

import "testing"

func Test(t *testing.T) {

	assertCorrectMessage := func(t *testing.T, got, want int) {
		t.Helper()
		if got != want {
			t.Errorf("got '%d' want '%d'", got, want)
		}
	}
	t.Run("should return 1 when sequence is 1", func(t *testing.T) {
		sequence := 1
		actual := getFibonacci(sequence)
		expected := 1

		assertCorrectMessage(t, actual, expected)
	})

	t.Run("should return 1 when sequence is 2", func(t *testing.T) {
		sequence := 2
		actual := getFibonacci(sequence)
		expected := 1

		assertCorrectMessage(t, actual, expected)
	})

	t.Run("should return 2 when sequence is 3", func(t *testing.T) {
		sequence := 3
		actual := getFibonacci(sequence)
		expected := 2

		assertCorrectMessage(t, actual, expected)
	})

}
