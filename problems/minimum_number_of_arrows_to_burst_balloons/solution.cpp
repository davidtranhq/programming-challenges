class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int last = points[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > last) {
                ++ans;
                last = points[i][1];
            } else {
                last = min(last, points[i][1]); 
            }
        }
        return ans;
    }
};