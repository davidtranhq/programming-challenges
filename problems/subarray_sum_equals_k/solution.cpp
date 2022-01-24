class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sums;
        sums[0] = 1;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ans += sums[sum - k];
            ++sums[sum];
        }
        return ans;
    }
};