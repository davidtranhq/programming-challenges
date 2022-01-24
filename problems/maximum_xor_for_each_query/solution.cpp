/* scratch:

let n := nums.size()
then k = ~(nums[0] xor nums[1] xor ... nums[n -1]) (bits after maximum bit cleared)

*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1 << maximumBit) - 1;
        int n = nums.size();
        vector<int> ans(n);
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x ^= nums[i];
            ans[n - i - 1] = ~x & mask;
        }
        return ans;
    }
};