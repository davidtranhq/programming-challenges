class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMoves, int startRow, int startColumn) {
        dp.resize(m * n, vector<int>(maxMoves + 1, -1));
        return dfs(m, n, maxMoves, startRow, startColumn);
    }
    
    int dfs(int m, int n, int moves, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return 1;
        if (moves == 0)
            return 0;
        int i = row * n + col;
        if (dp[i][moves] != -1)
            return dp[i][moves];
        int ans = ((dfs(m, n, moves - 1, row - 1, col) 
            + dfs(m, n, moves - 1, row, col - 1)) % mod
            + dfs(m, n, moves - 1, row + 1, col)) % mod
            + dfs(m, n, moves - 1, row, col + 1);
        ans %= mod;
        dp[i][moves] = ans;
        return ans;
    }
};