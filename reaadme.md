# CMP2103 - OOP with C++
## Chapter 03 Group Assignment
### Group 9 - Cumulative Operations

## 1. Task Requirements

The task was to implement and test a set of cumulative and rolling operations using C++ vectors.

The program contains the following five functions:

1. `cumulative_min()` - returns the smallest value encountered up to each position in the vector.
2. `cumulative_max()` - returns the largest value encountered up to each position.
3. `cumulative_mean()` - calculates the running average of the values.
4. `rolling_sum()` - calculates the sum of values within a fixed-size moving window.
5. `rolling_mean()` - calculates the average of values within a fixed-size moving window.

The `main()` function is used to provide sample input data, call each of the functions, and display the results.

---

## 2. Implementation Strategy

The program uses `vector<double>` to store both the input data and the results of each operation.

For the cumulative functions, the program moves through the input vector from left to right while keeping track of the required value.

- `cumulative_min()` keeps track of the smallest value found so far.
- `cumulative_max()` keeps track of the largest value found so far.
- `cumulative_mean()` keeps a running sum and divides it by the number of elements processed.

For the rolling functions, a fixed window is moved across the vector.

For example, with a window size of 3:

```text
Input: {4, 2, 7, 1, 9, 3}

Window 1: {4, 2, 7}
Window 2: {2, 7, 1}
Window 3: {7, 1, 9}
Window 4: {1, 9, 3}