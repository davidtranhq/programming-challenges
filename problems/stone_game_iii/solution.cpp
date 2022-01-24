class Solution {
public:
    vector<int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n, numeric_limits<int>::min());
        int res = dfs(0, true, stoneValue);
        if (res > 0)
            return "Alice";
        else if (res < 0)
            return "Bob";
        else
            return "Tie";
    }
    
    // i: next stone that can be picked, k: stones left to be picked
    // returns alice - bob (if negative, alice wins)
    int dfs(int i, bool aliceTurn, const vector<int> &val) {
        int n = val.size();
        if (i >= n) {
            return 0;
        }
        if (dp[i] != numeric_limits<int>::min())
            return dp[i];
        int score = numeric_limits<int>::min();
        for (int j = 0; j < 3 && i + j < n; ++j) {
            int thisTurn = accumulate(val.cbegin() + i, val.cbegin() + i + j + 1, 0);
            int nextTurn = dfs(i + j + 1, !aliceTurn, val);
            score = max(score, thisTurn - nextTurn);
        }
        dp[i] = score;
        return score;
    }
};