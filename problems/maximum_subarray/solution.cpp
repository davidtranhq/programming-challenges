class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum = max(sum + nums[i], nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};