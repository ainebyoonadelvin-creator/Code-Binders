 ============================================================
    CMP2103 : Object Oriented Programming with C++
    Group Assignment : Chapter 03
    GROUP 9 : CUMULATIVE OPERATIONS
    ============================================================

    Functions assigned to Group 9:
        1. cumulative_min()
        2. cumulative_max()
        3. cumulative_mean()
        4. rolling_sum()
        5. rolling_mean()

    WHAT THIS PROGRAM DOES (Psuedocode):
    --------------------------------------------
    Imagine you have a list of numbers, e.g. daily temperatures:
        [20, 25, 18, 30, 22]

    - "Cumulative" functions look at the numbers ONE AT A TIME,
      from the start of the list up to the current position, and
      keep a running record (e.g. the smallest value SO FAR, the
      largest value SO FAR, the average SO FAR).

    - "Rolling" also called sliding window, functions only look
      at the last N numbers at any point (a fixed-size "window"
      that slides along the list), instead of everything from the
      very beginning.

    This is the kind of logic used in real life for things like:
      - A 7-day rolling average of temperature or stock prices
      - The highest score a student has achieved so far in a term
      - Tracking a running total of expenses

    ============================================================

     The line "using namespace std;" means we can write "vector" and "cout" instead of
    "std::vector" and "std::cout" everywhere. It saves typing but is
    only considered safe in small programs like this one.

    ------------------------------------------------------------
    FUNCTION 1: cumulative_min
    ------------------------------------------------------------
    PURPOSE: For every position i in the list, find the smallest
    value seen from index 0 up to and including index i.

    Example:
        input  = [5, 2, 9, 1, 7]
        output = [5, 2, 2, 1, 1]

    HOW IT WORKS:
    - We start by assuming the running minimum is the very first
      number.
    - We then walk through the rest of the list one number at a
      time. Each time we see a number smaller than our current
      running minimum, we update the running minimum.
    - At every step we save whatever the running minimum is at
      that moment into the result list.

     "const vector<double>&" means that the user requests for the list, lets them read
     it, but can not change the caller's original list,
     and doesn't waste time/memory copying it (that's what "&" does).



    ------------------------------------------------------------
    FUNCTION 2: cumulative_max
    ------------------------------------------------------------
    Exactly the same idea as cumulative_min, but tracking the
    largest value seen so far instead of the smallest.

    Example:
        input  = [5, 2, 9, 1, 7]
        output = [5, 5, 9, 9, 9]



    ------------------------------------------------------------
    FUNCTION 3: cumulative_mean
    ------------------------------------------------------------
    For every position i, find the AVERAGE of all values from
    index 0 to index i.

    Example:
        input  = [4, 8, 6]
        output = [4.0, 6.0, 6.0]
        ((4/1)=4, (4+8)/2=6, (4+8+6)/3=6)

    HOW IT WORKS:
    - We keep a running total ("running_sum") of everything we've
      seen so far.
    - At each position, the mean so far = running_sum / (how many
      numbers we've added so far, i.e. i + 1).


    ------------------------------------------------------------
    FUNCTION 4: rolling_sum
    ------------------------------------------------------------
    Unlike the "cumulative" functions above, this one does not
    look all the way back to the start of the list. Instead it
    only adds up the last "window_size" numbers.

    Example: window_size = 3
        input  = [1, 2, 3, 4, 5]
        output = [ _, _, 6, 9, 12]
        (positions 0 and 1 don't have 3 numbers behind them yet,
         so there is no valid rolling sum for them)

        index 2 -> 1+2+3 = 6
        index 3 -> 2+3+4 = 9
        index 4 -> 3+4+5 = 12

  
    FUNCTION 5: rolling_mean
    ------------------------------------------------------------
    Same sliding-window idea as rolling_sum, but reports the
    AVERAGE of the window instead of the total.

    Example: window_size = 3
        input  = [1, 2, 3, 4, 5]
        output = [0, 0, 2, 3, 4]
        (6/3=2, 9/3=3, 12/3=4)

    This function reuses rolling_sum instead of rewriting
    the same sliding-window logic again. This helps to avoid duplicated code and means a bug in rolling_sum
    is automatically fixed here too.


    ------------------------------------------------------------
    HELPER FUNCTION: print_vector
    ------------------------------------------------------------
    Not one of the assigned functions — just a small tool we wrote
    ourselves to neatly display a vector of numbers on screen so we
    can visually check our results. Good practice: keep "helper" or
    "utility" code clearly separate from the graded functions.


    ------------------------------------------------------------
    main() : program entry point
    ------------------------------------------------------------
    Every C++ program starts running from main(). This is where we
    demonstrate that all 5 Group 9 functions work correctly using a
    sample data set, before the file is combined with the other
    groups' functions into the full assignment.
