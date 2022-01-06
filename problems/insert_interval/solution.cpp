class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> res;
        int i = 0;
        while (i < n && intervals[i][1] < start) {
            res.push_back(intervals[i++]);
        }
        while (i < n && intervals[i][0] <= end) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};