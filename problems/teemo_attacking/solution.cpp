/* scratch

timeSeries = [1, 2, 3, 4], duration = 2

1 2 3 4 5
* * * * *

[1, 3, 5, 6], duration = 3

1 2 3 4 5 6 7 8 9
* * * * * * * *

overlap: 2, 2 => 1
3, 2 => 2
1, 2 => 0

*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int next = timeSeries[i] + duration - 1;
            int overlap = max(next - timeSeries[i + 1] + 1, 0);
            res += duration - overlap;
        }
        return res + duration;
    }
};