/* scratch:

sort intervals by endpoint
prevEnd = intervals[0][1]
for each interval {
    compare with previous
    if (intervals overlap) {
        create new interval with min start and max end
        push interval to v
        prevEnd = max end
    } else {
        prevEnd = interval[1]
    }
}

*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            const vector<int> &iv = intervals[i];
            vector<int> &prevIv = ans.back();
            if (iv[0] <= prevIv[1]) {
                prevIv[1] = max(iv[1], prevIv[1]);
            } else {
                ans.push_back(iv);
            }
        }
        return ans;
    }
};