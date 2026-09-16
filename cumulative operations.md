Group 9 — Cumulative Operations

 Task Requirements

 Implement the following cumulative and rolling operations in C++:

- cumulative_min
- cumulative_max
- cumulative_mean
- rolling_sum
- rolling_mean

 Each function should accept a vector of numbers and return the calculated results.

  Implementation Strategy

 The solution uses vector<double> to store the input data.

- **Cumulative functions** process the data from the beginning and keep track of the result so far.
- **Rolling functions** use a fixed-size window that moves through the vector.
- A helper function, printVector(), is used to display results.
- Input validation is included for empty data and invalid window sizes.

 Key Decisions

- const vector<double>& is used to avoid unnecessary copying and prevent modification of the input.
- double is used to support decimal values.
- The rolling window is passed as an int.
- Results are displayed to two decimal places.

 Testing

 The functions were tested using:

Input data: {4, 2, 7, 1, 9, 3}
Window: 3

 Expected Output

cumulative_min  : 4.00  2.00  2.00  1.00  1.00  1.00
cumulative_max  : 4.00  4.00  7.00  7.00  9.00  9.00
cumulative_mean : 4.00  3.00  4.33  3.50  4.60  4.33
rolling_sum     : 13.00  10.00  17.00  13.00
rolling_mean    : 4.33  3.33  5.67  4.33

  Working Example

 For the rolling window of 3:

{4, 2, 7} → 13.00
{2, 7, 1} → 10.00
{7, 1, 9} → 17.00
{1, 9, 3} → 13.00

