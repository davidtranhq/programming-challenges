/* scratch:

1001
0110
0100
0010
0011
0101
0111
0000
0001

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return (nums.size() * (nums.size() + 1)) / 2 
            - accumulate(nums.begin(), nums.end(), 0);
    }
};