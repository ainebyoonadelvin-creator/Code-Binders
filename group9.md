
# Group 9 — Cumulative Operations (C++ Re-implementation)

## Exercise

Data processing engines such as **Polars** and **Pandas** use arrays and
matrix-like data structures to process and analyze data. This exercise
re-implements, in C++, the following dataframe operations:

- `cumulative_min()`
- `cumulative_max()`
- `cumulative_mean()`
- `rolling_sum()`
- `rolling_mean()`

## Approach

A dataframe column is modeled as a `std::vector<double>` wrapped in a small
`Column` class. Each operation walks the array once (O(n)) and builds a new
`Column` of the same length, matching the shape Pandas/Polars return.

| Operation | Definition | Warm-up behavior |
|---|---|---|
| `cumulative_min` | Running minimum of all values up to index `i` | Defined from index 0 |
| `cumulative_max` | Running maximum of all values up to index `i` | Defined from index 0 |
| `cumulative_mean` | Running average of all values up to index `i` | Defined from index 0 |
| `rolling_sum(w)` | Sum of the last `w` values ending at index `i` | `NaN` until `w` values are available |
| `rolling_mean(w)` | Average of the last `w` values ending at index `i` | `NaN` until `w` values are available |

`rolling_sum` uses a sliding-window running total (add the incoming value,
subtract the value that falls out of the window) so it stays O(n) instead of
re-summing the window at every step. `rolling_mean` reuses `rolling_sum` and
divides by the window size.

## Sample run

Input column: `4, 2, 9, 1, 7, 5, 8, 3`, window size `3`.

```
original          : 4.00    2.00    9.00    1.00    7.00    5.00    8.00    3.00
cumulative_min    : 4.00    2.00    2.00    1.00    1.00    1.00    1.00    1.00
cumulative_max    : 4.00    4.00    9.00    9.00    9.00    9.00    9.00    9.00
cumulative_mean   : 4.00    3.00    5.00    4.00    4.60    4.67    5.14    4.88
rolling_sum(3)    : NaN     NaN     15.00   12.00   17.00   13.00   20.00   16.00
rolling_mean(3)   : NaN     NaN     5.00    4.00    5.67    4.33    6.67    5.33
```

## Files

- `cumulative_ops.cpp` — full C++ source, compiles with `g++ -std=c++17 cumulative_ops.cpp -o cumulative_ops`.

## Notes / possible extensions

- `rolling_sum`/`rolling_mean` currently require a full window before
  producing a value (matching Pandas' default `min_periods == window`). A
  `min_periods` parameter could be added to relax this.
- The `Column` class could be generalized to a full dataframe (multiple
  named columns) by wrapping several `Column` instances in a map.
cumulative_ops.md
Displaying cumulative_ops.md.
