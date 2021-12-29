/* scratch:

dfs(i, j): max value with j events left to attend and i being the last event attended

ans = 0
for i = 0 to n - 1:
    ans = max(ans, dfs(i, j - 1))

*/

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int ans = 0;
        int n = events.size();
        vector<vector<int>> cache(n, vector<int>(k));
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, k - 1, events, cache));
        }
        return ans;
    }
    
    int dfs(int last, int k, const vector<vector<int>> &events, vector<vector<int>> &cache) {
        int last_val = events[last][2];
        if (k == 0) {
            return last_val;
        }
        if (cache[last][k] != 0)
            return cache[last][k];
        int most = last_val;
        int n = events.size();
        for (int i = 0; i < n; ++i) {
            if (events[i][0] <= events[last][1])
                continue;
            most = max(most, last_val + dfs(i, k - 1, events, cache));
        }
        cache[last][k] = most;
        return most;
    }
};