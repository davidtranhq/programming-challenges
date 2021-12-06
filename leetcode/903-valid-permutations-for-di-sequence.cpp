class Solution {
public:
    /* better explanation:
        The intuition behind this solution is that the the number of future valid permutations for a certain string
        depends only on:
            1. the remaining number of unused digits 
                smaller than the most recently added digit d (the (i - 1)th digit of the string)
            2. the remaining number of unused digits
                greater than the most recently added digit d
        This is because (1) and (2) tell us what DI sequences are possible. For example, suppose our digit pool is
        (0, 1, 2, 3), so n = 3. The following strings "31", "21" have the unused digits (0, 2) and (0, 3), respectively.
        Since the last digit is "1" in each, each string has one unused d-greater digit and one unused d-smaller digit.
        So, each string can be followed up by a "DI" sequence or an "ID" sequence, but not a "DD" or "II" sequence.
        So, they both have the same number of future permutations. We store strings with the same number of future 
        permutations together so that we can use them for DP recursion.
        
        Notice that we only need (1) or (2) but not both, since one can be used to compute the other. e.g: if there
        are n digits, and there are 2 unused d-smaller digits, then there must be n - 2 - 1 unused d-greater digits (-1 because the
        last digit is the digit d itself). So, we store the DP results as perms[i][j], representing the number of permutations
        for a string of length i + 1 with j unused d-smaller digits. The final answer will be stored in perms[n][0]
        (n + 1 digits, and consequently 0 unused d-smaller digits (and also 0 unused d-greater digits)).
        
        The base cases are perms[0][0], perms[0][1], ... perms[0][n]. They each have a value of 1 (since
        the string is of length 0 + 1 = 1, so there is only one permutation). In perms[0][0], we use the digit 0, so there
        are 0 unused d-smaller digits. In perms[0][1], we use the digit 1, so there is 1 unused d-smaller digit (0), etc.
        
        We show how to compute perms[i + 1][j] if s[i] == 'D', since the reasoning for s[i] == 'I' follows symmetrically.
        
        Consider only when j = 0. The permutations we use to generate perms[i + 1][0] are the values
        in perms[i] that have at least 1 unused d-smaller digit. By the way we defined perms[i][j], these are the values where j >= 1,
        e.g. perms[i][1], perms[i][2], ..., perms[i][n - i].
        So perms[i + 1][0] = perms[i][1] + perms[i][2] + ... + perms[i][n - 1]
        
        Now consider when j = 1. The permutations we use to generate perms[i + 1][1] are the values in perms[i] that have at least
        2 unused d-smaller digits. We need at least 2 because to maintain the condition that j represents the number of unused 
        d-smaller digits, we must choose d to be the 1st smallest (0-indexed, so 0th is the smallest) unused digit, so that there
        is still j = 1 digit smaller than d. So, we use the values perms[i][j] where j >= 2.
        So perms[i + 1][1] = perms[i][2] + perms[i][3] + ... + perms[i][n - 1]
        
        The pattern to notice here is that perms[i + 1][j] = perms[i][j + 1] + perms[i][j + 2] + ... + perms[i][n - 1].
    */
    
    /* scratch:
    approach with dynamic programming
    
    let perms[i][j] be the number of perms with i + 1 numbers
    where the ith number (most recent) is the jth smallest
    
    so at perms[i][j], there are n - j - i bigger numbers to choose from, j smaller numbers to choose from
    
    e.g. n = 3.
    
    perms[0][3] = 1 (3) (3 - 3 - 0) = 0 bigger numbers to choose from, 3 smaller numbers to choose from (2, 1, 0)
    perms[0][2] = 1 (2) (3 - 2 - 0) = 1 bigger number to choose from (3), 2 smaller (0, 1)
    perms[0][1] = 1 (1), 2 bigger numbers to choose from (3, 2), 1 smaller (0)
    perms[0][0] = 1 (0), 3 bigger numbers to choose from (1, 2, 3), 0 smaller
    
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
        // time O(n^2)
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