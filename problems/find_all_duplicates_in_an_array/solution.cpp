/* scratch:

use the fact that integers range from [1, n]

[4, 3, 2, 7, 8, 2, 3, 1]

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                ans.push_back(idx + 1);
            }
            nums[idx] *= -1;
        }
        return ans;
    }
};