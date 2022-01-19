class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int n = nums.size();
        unsigned mod = 1e9 + 7;
        unsigned ans = 0;
        for (int i = 0, j = 1, k = 1; i < n - 2; ++i) {
            j = max(i + 1, j);
            while (j < n - 1 && nums[j] - nums[i] < nums[i])
                ++j;
            k = max(j, k);
            while (k < n - 1 && nums[k] - nums[i] <= nums.back() - nums[k])
                ++k;
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};