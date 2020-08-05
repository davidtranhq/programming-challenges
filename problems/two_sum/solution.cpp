class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i {0}, j {0};
        auto len = nums.size();
        for (i = 0; i < len-1; ++i) {
            int a {nums[i]};
            for (j = i+1; j < len; ++j) {
                if (a + nums[j] == target)
                    return vector<int> {i, j};
            }
        }
        return vector<int> {};
    }
};