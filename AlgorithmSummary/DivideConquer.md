# Algorithm: Divide and Conquer

Divide and Conquer is an algorithmic paradigm. A typical Divide and Conquer algorithm solves a problem using following three steps.
- Divide: Break the given problem into subproblems of same type.
- Conquer: Recursively solve these subproblems
- Combine: Appropriately combine the answers


## D&C vs DP
Both paradigms (D & C and DP) divide the given problem into subproblems and solve subproblems. How to choose one of them for a given problem? Divide and Conquer should be used when same subproblems are not evaluated many times. Otherwise Dynamic Programming or Memoization should be used. For example, Binary Search is a Divide and Conquer algorithm, we never evaluate the same subproblems again. On the other hand, for calculating nth Fibonacci number, Dynamic Programming should be preferred (See this for details).

## Implementation
- Merge Sort
- Binary Search
- Quick Sort
- Tower of Hanoi
