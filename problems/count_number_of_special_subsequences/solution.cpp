/* scratch:

Let p_i be the number of permutations if the ith number is chosen.

p_i = \sum_{k = i}^n p_k if nums[i] <= nums[k] <= nums[i] + 1

for i = n - 1 to 0:
    for j = i to n - 1:
        if A[j] == A[i] || A[j] == A[i] + 1:
            dp[i] += dp[j]
    if (nums[i] == 2)
        dp[i] += 1
ans = 0
for i = 0 to n - 1:
    if (A[i] == 0):
        ans += dp[i]

O(n^2)

TLE...

dp[i][j] = sum of dp[i'][j] where i' > i

Time: O(n)
Space: O(n)

------------
Even better...

dp[i]: 0 <= i <= 2
dp[0] = number of special subsequences [0, ...]
dp[1] = number of special subsequences [.., 1... ,]
dp[2] = number of special subsequences [..., ..., 2, ...]


*/

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        unsigned long long mod = 1e9 + 7;
        vector<unsigned long long> dp = {0, 0, 0};
        for (int x : nums) {
            switch (x) {
                case 0: dp[0] += dp[0] + 1; break;
                case 1: dp[1] += dp[0] + dp[1]; break;
                case 2: dp[2] += dp[1] + dp[2]; break;
            }
            dp[x] %= mod;
        }
        return dp[2];
    }
};