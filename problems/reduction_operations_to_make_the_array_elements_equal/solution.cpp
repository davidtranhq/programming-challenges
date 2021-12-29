/* scratch:
operations are finished when largest = smallest at the beginning
---------------
method 1: brute force
find smallest // O(n)
find largest // O(n)
ans = 0;
while (largest != smallest):
    find nextLargest
    largest = nextLargest
    ans += 1
return ans;

Time: O(n^2)
Space: O(1)
---------------------
*/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1)
            return 0;
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] != nums[i + 1]) {
                ans += n - i - 1;
            }
        }
        return ans;
    }
};