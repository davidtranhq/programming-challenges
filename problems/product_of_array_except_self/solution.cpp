class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;
        ans[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            nums[i] *= nums[i - 1];
            ans[n - 1 - i] *= ans[n - i];
        }
        for (int i = 0; i < n; ++i) {
            int a = i > 0 ? nums[i - 1] : 1;
            int b = i < n - 1 ? ans[i + 1] : 1;
            ans[i] = a * b;
        }
        return ans;
    }
};