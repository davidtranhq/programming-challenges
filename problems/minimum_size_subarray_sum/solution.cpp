class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, n = nums.size();
        int ans = n + 1;
        while (j < n) {
            sum += nums[j++];
            while (sum >= target) {
                ans = min(ans, j - i);
                sum -= nums[i++];
            }
        }
        return ans > n ? 0 : ans;
    }
};