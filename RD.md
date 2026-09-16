# Group 9 — Cumulative Operations

## 1. Task Requirements

The task is to implement five data-processing operations using C++:

1. `cumulative_min()`
2. `cumulative_max()`
3. `cumulative_mean()`
4. `rolling_sum()`
5. `rolling_mean()`

The operations work on numerical array-like data represented using the C++ `vector` container.

The cumulative operations process the data from the beginning, while the rolling operations process the data using a fixed-size moving window.
## 2. Implementation Strategy

The program uses:
* `vector<double>` to store numerical data.
* Separate functions for each required operation.
* Loops to process the elements.
* `push_back()` to store calculated results.
* A helper function called `printVector()` to display results.
* A rolling window size supplied as an integer.
Each function receives the input vector using `const vector<double>&`. This allows the function to read the original data without modifying it or unnecessarily copying it.
## 3. Operations Implemented
### 3.1 Cumulative Minimum
`cumulative_min()` calculates the minimum value encountered from the beginning of the data up to each position.
Example:
text
Input:
4 2 7 1 9 3

Output:
4 2 2 1 1 1
For example, after reaching `7`, the minimum is still `2`. After reaching `1`, the minimum becomes `1`.
### 3.2 Cumulative Maximum
`cumulative_max()` calculates the maximum value encountered from the beginning of the data up to each position.

Example:

text
Input:
4 2 7 1 9 3

Output:
4 4 7 7 9 9
### 3.3 Cumulative Mean

`cumulative_mean()` calculates the running average.

Example:

text
Input:
4 2 7 1 9 3

Output:
4.00 3.00 4.33 3.50 4.60 4.33
For example:
text
First three values:
(4 + 2 + 7) / 3 = 4.33
### 3.4 Rolling Sum

`rolling_sum()` calculates the sum of values inside a fixed-size moving window.

A window size of `3` is used.

Example:
text
Input:
4 2 7 1 9 3

Window:
3
The windows are:
text
4 2 7  -> 13
2 7 1  -> 10
7 1 9  -> 17
1 9 3  -> 13
Therefore:
text
Output:
13.00 10.00 17.00 13.00
### 3.5 Rolling Mean

`rolling_mean()` calculates the average of each moving window.

Using a window size of `3`:
text
4 2 7  -> 13 / 3 = 4.33
2 7 1  -> 10 / 3 = 3.33
7 1 9  -> 17 / 3 = 5.67
1 9 3  -> 13 / 3 = 4.33
Therefore:
text
Output:
4.33 3.33 5.67 4.33
## 4. Key Decisions and Approaches

### Use of `vector<double>`

A C++ vector was selected because it provides a convenient dynamic array for numerical data.

`double` was used because mean calculations can produce decimal values.

### Separate Functions

Each operation is implemented as an independent function:
ext
cumulative_min()
cumulative_max()
cumulative_mean()
rolling_sum()
rolling_mean()
This makes the code easier to understand, test, and maintain.

### Input Validation

The rolling functions check whether:

* The data is empty.
* The window size is less than or equal to zero.
* The window size is larger than the number of data elements.

If the window is invalid, the operation is skipped.

### Fixed Window

A window size of `3` is used in the working example to demonstrate how rolling operations move through the data.
## 5. Testing

The program was tested using:
text
Data:
4 2 7 1 9 3

Window:
3
The expected results were calculated manually and compared with the program output.

### Expected Results

 Operation           Expected Output 
 Cumulative Minimum  4.00 2.00 2.00 1.00 1.00 1.00 
 Cumulative Maximum  4.00 4.00 7.00 7.00 9.00 9.00 
Cumulative Mean     4.00 3.00 4.33 3.50 4.60 4.33 
 Rolling Sum         13.00 10.00 17.00 13.00       
 Rolling Mean        4.33 3.33 5.67 4.33           

The program output was compared against these expected values.
## 6. Working Example

### Input

text
Original data:
4 2 7 1 9 3

Rolling window:
3


### Output

text
GROUP 9 - CUMULATIVE OPERATIONS
Original data   : 4.00  2.00  7.00  1.00  9.00  3.00

Cumulative (window grows)
cumulative_min  : 4.00  2.00  2.00  1.00  1.00  1.00
cumulative_max  : 4.00  4.00  7.00  7.00  9.00  9.00
cumulative_mean : 4.00  3.00  4.33  3.50  4.60  4.33

Rolling (window = 3)
rolling_sum     : 13.00  10.00  17.00  13.00
rolling_mean    : 4.33  3.33  5.67  4.33
## 7. How to Compile and Run

Using a C++ compiler such as `g++`:
bash
g++ group9_cumulative_operations.cpp -o group9
Run the program:
bash
./group9

On Windows:
bash
group9.exe
## 8. Conclusion

Our Group 9 program successfully implements cumulative minimum, cumulative maximum, cumulative mean, rolling sum, and rolling mean operations.

The program also validates rolling-window input and provides a working example demonstrating the results of each operation.
