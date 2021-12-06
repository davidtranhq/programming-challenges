class Solution {
public:
    /*
    approach with dynamic programming
    
    let perms[i][j] be the number of perms with i + 1 numbers
    where the ith number (most recent) is the jth smallest
    
    so at perms[i][j], there are n - j - i bigger numbers to choose from, j smaller numbers to choose from
    
    e.g. n = 3.
    
    perms[0][3] = 1 (3) (3 - 3 - 0) = 0 bigger numbers to choose from, 3 smaller numbers to choose from (2, 1, 0)
    perms[0][2] = 1 (2) (3 - 2 - 0) = 1 bigger number to choose from (3), 2 smaller (0, 1)
    perms[0][1] = 1 (1)
    perms[0][0] = 1 (0)
    
    'D'
    
    perms[1][2] = 1 (32) (3 - 2 - 1) = 0 bigger numbers to choose from, 2 smaller (1, 0)
    perms[1][1] = 2 (31, 21), 1 bigger number to choose from, 1 smaller to choose
    perms[1][0] = 3 (10, 20, 30), 2 bigger numbers to choose from, 0 smaller to choose
    
    
    'I'
    
    perms[2][1] = (103, 203, 302, 312, 213) 1 smaller to choose from
    perms[2][0] = (102, 201, 301) 0 smaller to choose from
    
    'D'
    
    perms[3][0] = (1032, 2031, 3021, 3120, 2130)
    
    algo:
    populate base case: perms[0][j] = 1
    for i to n + 1:
        ch = s[i]
        if s[i] == 'D':
            // loop through elements in previous layer that have at least one smaller number to take from
            // keeping track of the accumulated perms (since a perm [i][j] can take from every one above it)
            acc = 0
            for j from n - i - 1 to 0 inclusive:
                acc += perms[i][j + 1] mod max
                perms[i + 1][j] = acc
        else
            // loop through elements in previous layer that have at least one larger number to take from
            acc = 0
            for j from 0 to n - i exclusive:
                acc += perms[i][j] mod max
                perms[i + 1][j] = acc
                
        
    */
    int numPermsDISequence(string s) {
        unsigned long p = 1e9 + 7;
        int n = s.size();
        vector<vector<unsigned long>> perms(n + 1, vector<unsigned long>(n + 1, 1)); // space O(n^2)
        for (int i = 0; i < n + 1; ++i)
        {
            char ch = s[i];
            unsigned long acc = 0;
            if (ch == 'D')
            {
                for (int j = n - i - 1; j >= 0; --j)
                {
                    acc += perms[i][j + 1] % p;
                    perms[i + 1][j] = acc;
                }
            }
            else
            {
                for (int j = 0; j < n - i; ++j)
                {
                    acc += perms[i][j] % p;
                    perms[i + 1][j] = acc;
                }
            }
        }
        return perms[n][0];
    }
};