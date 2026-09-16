
#include <iostream> // Lets us use std::cin and std::cout (input/output)
#include <vector>   // Lets us use std::vector, a resizable array
#include <iomanip>  // Lets us format decimal output (e.g. 2 decimal places)
#include <stdexcept> // Lets us "throw" proper error messages (exceptions)

using namespace std;

vector<double> cumulative_min(const vector<double>& data) {
   

    vector<double> result;       // this will hold our running minimums
    result.reserve(data.size()); // pre-allocate space, purely for efficiency

    if (data.empty()) {
        // If the list is empty, there is nothing to compute.
        // We return an empty result instead of crashing.
        return result;
    }

    double running_min = data[0]; // start the running minimum at the first element
    result.push_back(running_min);

    for (size_t i = 1; i < data.size(); i++) {
        // size_t is an unsigned integer type used for sizes/indices in C++.
        if (data[i] < running_min) {
            running_min = data[i]; // found a new smaller value, update it
        }
        result.push_back(running_min); // record the running minimum so far
    }

    return result;
}


vector<double> cumulative_max(const vector<double>& data) {
    vector<double> result;
    result.reserve(data.size());

    if (data.empty()) {
        return result;
    }

    double running_max = data[0];
    result.push_back(running_max);

    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] > running_max) {
            running_max = data[i];
        }
        result.push_back(running_max);
    }

    return result;
}


vector<double> cumulative_mean(const vector<double>& data) {
    vector<double> result;
    result.reserve(data.size());

    double running_sum = 0.0;

    for (size_t i = 0; i < data.size(); i++) {
        running_sum += data[i];              // add the current number to the total
        result.push_back(running_sum / (i + 1)); // divide by how many numbers so far
    }

    return result;
}


vector<double> rolling_sum(const vector<double>& data, int window_size) {
    vector<double> result(data.size(), 0.0);
    // vector<double> result(N, 0.0) creates a vector of size N where
    // every value is initialised to 0.0.

    if (window_size <= 0) {
        // A window of size 0 or a negative size makes no logical sense.
        throw invalid_argument("window_size must be a positive whole number");
    }

    double window_total = 0.0;

    for (size_t i = 0; i < data.size(); i++) {
        window_total += data[i]; // add the newest number into the window

        if (i >= static_cast<size_t>(window_size)) {
            
            window_total -= data[i - window_size];
        }

        if (i >= static_cast<size_t>(window_size) - 1) {
            // Only once we've accumulated at least "window_size"
            // numbers do we have a real rolling sum to report.
            result[i] = window_total;
        }
        // Otherwise result[i] stays at its default value, 0.0.
    }

    return result;
}


vector<double> rolling_mean(const vector<double>& data, int window_size) {
    vector<double> sums = rolling_sum(data, window_size); // reuse Function 4
    vector<double> result(data.size(), 0.0);

    for (size_t i = 0; i < data.size(); i++) {
        if (i >= static_cast<size_t>(window_size) - 1) {
            result[i] = sums[i] / window_size;
        }
    }

    return result;
}



void print_vector(const string& label, const vector<double>& v) {
    cout << left << setw(18) << label << ": [ ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << fixed << setprecision(2) << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;
}



int main() {
    // Sample dataset: could represent anything (temperatures, sales
    // figures, exam scores...). Feel free to change these numbers.
    vector<double> data = {10, 15, 7, 22, 18, 30, 5, 12};
    int window_size = 3; // the size of the "window" for rolling functions

    cout << "GROUP 9 - CUMULATIVE & ROLLING OPERATIONS DEMO\n";
    cout << "================================================\n";
    print_vector("Original data", data);
    cout << "------------------------------------------------\n";

    print_vector("cumulative_min",  cumulative_min(data));
    print_vector("cumulative_max",  cumulative_max(data));
    print_vector("cumulative_mean", cumulative_mean(data));

    cout << "------------------------------------------------\n";
    cout << "(rolling functions using window_size = " << window_size << ")\n";
    print_vector("rolling_sum",  rolling_sum(data, window_size));
    print_vector("rolling_mean", rolling_mean(data, window_size));

    return 0; // 0 tells the operating system the program finished successfully
}