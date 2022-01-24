/* scratch:
    start at first one, loop through and check manually
        
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        for (; i < n && nums[i] != 1; ++i)
            ;
        if (i == n) // no ones
            return true; // vacuously true
        i += 1;
        for (int last = i - 1; i < n; ++i) {
            if (nums[i] == 1) {
                if (i - last <= k)
                    return false;
                last = i;
            }
        }
        return true;
        
    }
};