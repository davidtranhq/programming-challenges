/* scratch:

dp[i] := shortest jumps to get to i
dp[i] = 1 + min(dp[j]) where j < i and nums[j] >= i - j

Time: O(n^2)
Space: O(n)

TLE..
--------------
attempt 2: work backwards
start at i = n - 1
search for smallest j such that nums[j] >= i - j
set i = j
repeat until i = 0


*/

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int i = n - 1;
        int ans = 0;
        while (i > 0) {
            int next = i;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] >= i - j)
                    next = j;
            }
            i = next;
            ++ans;
        }
        return ans;
    }
};