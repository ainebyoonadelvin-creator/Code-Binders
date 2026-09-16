/***********************************************************************
 * CMP2103 - OOP with C++  |  Chapter 03 - Group Assignment
 * GROUP 9 : CUMULATIVE OPERATIONS
 * Functions: cumulative_min, cumulative_max, cumulative_mean,
 *            rolling_sum, rolling_mean
 ***********************************************************************/

// ---------- 1. LIBRARIES ("toolboxes" we borrow code from) ----------
#include <iostream>  // gives us cout (print to screen) and cin (read input)
#include <vector>    // gives us vector = a resizable array
#include <string>    // gives us string = text
#include <iomanip>   // gives us setprecision = control decimal places

using namespace std; // lets us write 'cout' instead of 'std::cout'

// =====================================================================
// HELPER FUNCTION: prints a list of numbers with a label in front.
// 'void' means it returns NOTHING - it just prints.
// 'const ... &' means: use the original list, but PROMISE not to change it,
// and don't waste time copying it.
// =====================================================================
void printVector(const string& label, const vector<double>& v) {
    cout << label << " : ";
    for (double value : v) {      // visit every element, first to last
        cout << value << "  ";    // print it, then two spaces
    }
    cout << "\n";                 // new line after the list
}

// 1. CUMULATIVE MINIMUM by LUBANGAKENE DERRICK AND NAKIBINGE JEREMIAH
/* This section calculates the running minimum of a list of numbers. 
It tracks the smallest value seen so far as it moves through the vector from left to right.
Guard Clause: If the input list is empty, it immediately returns an empty result to prevent errors.
Initialization: It sets the first number as the starting minimum (currentMin) and adds it to the output list.
The Loop: It loops through the remaining numbers one by one.
The Condition: If it finds a number smaller than currentMin, it updates currentMin to that new value.Recording: 
It saves the currentMin (whether updated or unchanged) into the result list at each step*/
// input : {4, 2, 7, 1, 9, 3}   output: {4, 2, 2, 1, 1, 1}
vector<double> cumulative_min(const vector<double>& data) {
    vector<double> result;              // empty "answer box"

    if (data.empty()) return result;    // GUARD: no data -> return empty

    double currentMin = data[0];        // trust the 1st element as smallest
    result.push_back(currentMin);       // 1st output = 1st element

    for (size_t i = 1; i < data.size(); i++) {  // visit 2nd, 3rd, ...
        if (data[i] < currentMin) {     // smaller than our min so far?
            currentMin = data[i];       // yes -> it becomes the new min
        }
        result.push_back(currentMin);   // record min-so-far at this spot
    }
    return result;                      // hand the answer back
}

// 2. CUMULATIVE MAXIMUM by SSEMPIJJA IBRAHIM
/*This C++ function calculates the cumulative maximum of a list of numbers, tracking the highest value seen up to each point.
Handles empty input: It immediately returns an empty vector if the input is empty to avoid errors.
Initializes tracking: It sets the first element as the initial currentMax and adds it to the result list.
Loops through the data: It iterates through the remaining numbers one by one.
Updates the maximum: If the current number is strictly greater than currentMax, it updates currentMax to this new value.
Stores the result: It appends the updated currentMax to the result vector during each step of the loop.*/
// input : {4, 2, 7, 1, 9, 3}   output: {4, 4, 7, 7, 9, 9}
vector<double> cumulative_max(const vector<double>& data) {
    vector<double> result;
    if (data.empty()) return result;
    double currentMax = data[0];
    result.push_back(currentMax);

    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] > currentMax) {     // bigger than our max so far?
            currentMax = data[i];       // yes -> new max
        }
        result.push_back(currentMax);
    }
    return result;
}

// =====================================================================
// 3. CUMULATIVE MEAN (running average)
// input : {4, 2, 7, ...}  output: {4, 3, 4.33, ...}
// =====================================================================
vector<double> cumulative_mean(const vector<double>& data) {
    vector<double> result;
    if (data.empty()) return result;

    double sum = 0;                              // running total
    for (size_t i = 0; i < data.size(); i++) {
        sum += data[i];                          // add this element
        result.push_back(sum / (i + 1));         // total / how many so far
    }
    return result;
}

// =====================================================================
// 4. ROLLING SUM (window slides across the list)
// input : {4, 2, 7, 1, 9, 3}, window = 3
// output: {13, 10, 17, 13}  (4+2+7, 2+7+1, 7+1+9, 1+9+3)
// =====================================================================
vector<double> rolling_sum(const vector<double>& data, int window) {
    vector<double> result;
    int n = (int)data.size();   // number of elements, as a normal int

    // GUARD: reject empty data, or a silly window size
    if (n == 0 || window <= 0 || window > n) {
        cout << "  (rolling_sum skipped: empty data or invalid window)\n";
        return result;
    }

    for (int i = 0; i + window <= n; i++) {   // i = start of each window
        double sum = 0;                        // fresh total for this window
        for (int j = i; j < i + window; j++) { // walk inside the window
            sum += data[j];                    // add each element
        }
        result.push_back(sum);                 // store this window's total
    }
    return result;
}


// 5. ROLLING MEAN (average of each window) BY AINEBYOONA DELVIN
/*This function calculates a rolling sum by sliding a fixed-size window across a list of numbers and adding up the values inside it.
Safety Check:It first verifies that the input list isn't empty and that the window size is valid (greater than zero and not larger than the list itself). If invalid, it safely exits early.
Window Sliding: It loops through the list to find every possible starting point where a full window can fit without going past the end of the data.
Summation: For each starting position, it runs a second loop to add up the exact number of elements specified by the window size.
Output: It saves each calculated sum into a new list and returns it.Would you like to see how to optimize this code so it runs faster, or do you need help integrating it into a larger program?*/
// input : {4, 2, 7, 1, 9, 3}, window = 3
// output: {4.33, 3.33, 5.67, 4.33}
vector<double> rolling_mean(const vector<double>& data, int window) {
    vector<double> result;
    int n = (int)data.size();

    if (n == 0 || window <= 0 || window > n) {
        cout << "  (rolling_mean skipped: empty data or invalid window)\n";
        return result;
    }

    for (int i = 0; i + window <= n; i++) {
        double sum = 0;
        for (int j = i; j < i + window; j++) {
            sum += data[j];
        }
        result.push_back(sum / window);        // total / window size
    }
    return result;
}

// =====================================================================
// MAIN = the door the computer enters through. Execution starts here.
// =====================================================================
int main() {
    vector<double> data = {4, 2, 7, 1, 9, 3};  // our test numbers
    int window = 3;                            // sliding window size

    cout << fixed << setprecision(2);          // always show 2 decimals

    cout << "GROUP 9 - CUMULATIVE OPERATIONS\n";
    cout << "----------------------------------\n";
    printVector("Original data  ", data);
    cout << "\n-- Cumulative (window grows) --\n";
    printVector("cumulative_min ", cumulative_min(data));
    printVector("cumulative_max ", cumulative_max(data));
    printVector("cumulative_mean", cumulative_mean(data));
    cout << "\n-- Rolling (window = " << window << ") --\n";
    printVector("rolling_sum    ", rolling_sum(data, window));
    printVector("rolling_mean   ", rolling_mean(data, window));

    return 0;   // tell the OS: "program finished successfully"
}