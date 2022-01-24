/* scratch:

notice for any a > 0, b > 0, a & b <= a, b

for each index i, [i, j] is non-increasing


*/

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        set<int> prod; // AND prod of every subarray so far
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            set<int> tmp;
            tmp.insert(arr[i]);
            for (int x : prod)
                tmp.insert(arr[i] & x);
            for (int t : tmp)
                ans = min(ans, abs(target - t));
            prod = tmp;
        }
        return ans;
    }
};