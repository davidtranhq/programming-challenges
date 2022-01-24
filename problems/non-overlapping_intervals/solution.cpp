/* scratch:

sort intervals
for each interval in intervals {
    if interval overlaps with previous {
        remove interval with greater endpoint
        set previous to other interval
    } else {
        previous = current interval
    }
}

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int ans = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prevEnd) {
                ++ans;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};