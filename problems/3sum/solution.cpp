class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int y = nums[left], z = nums[right];
                if (x + y + z < 0) {
                    ++left;
                } else if (x + y + z > 0) {
                    --right;
                } else {
                    ans.push_back(vector<int> {x, y, z});
                    while (left < n && nums[left] == y)
                        ++left;
                    while (right >= 0 && nums[right] == z)
                        --right;
                }
            }
            while (i < n - 1 && nums[i + 1] == x)
                ++i;
        }
        return ans;
    }
};