class Solution {
public:
    /*
    note: an element is odd if it falls on the same row/column of an odd number of indices
    
    rows: {0, 1, 2, ... m} => (row, occurences)
    cols: {0, 1, 2, ... n} => (col, occurences)
    
    number of odds in rows * number of odds in cols
    
    create rows hashmap
    create cols hashmap
    for (row, col) in indices:
        ++rows[row]
        ++cols[col]
    odd_rows = number of odd values in rows
    odd_cols = number of odd values in cols
    
    odd_elements = odd_rows * n + odd_cols * m - 2 * odd_rows * odd_cols
    return odd_elements
    
    TEST EXAMPLE:
    rows: {(0, 1), (1, 1)}
    cols: {(1, 2)}
    
    odd_rows = 2
    odd_cols = 0
    
    odd_elements = 2 * 3 - 0
    
    Time: O(indices.length)
    Space: O(m + n)
    */
    static bool isOdd(pair<const int, int> x)
    {
        return x.second % 2 == 1;
    }
    
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int odd_rows = 0, odd_cols = 0;
        map<int, int> rows, cols;
        for (const vector<int> &index : indices)
        {
            int row = index[0];
            int col = index[1];
            if (rows[row] % 2 == 1)
                --odd_rows;
            else
                ++odd_rows;
            if (cols[col] % 2 == 1)
                --odd_cols;
            else
                ++odd_cols;
            ++rows[row];
            ++cols[col];
        }
        return odd_rows * n + odd_cols * m - 2 * odd_cols * odd_rows;
    }
};