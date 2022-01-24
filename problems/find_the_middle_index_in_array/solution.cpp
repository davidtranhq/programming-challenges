class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int i = 0, left = 0, right = accumulate(nums.cbegin() + 1, nums.cend(), 0);
        for (i = 0; i < n - 1 && left != right; ++i) {
            left += nums[i];
            right -= nums[i + 1];
        }
        return left == right ? i : -1;
    }
};