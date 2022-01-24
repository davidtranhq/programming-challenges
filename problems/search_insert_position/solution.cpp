class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int x = nums[mid];
            if (x > target)
                hi = mid - 1;
            else if (x < target)
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }
};