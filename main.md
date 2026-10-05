
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