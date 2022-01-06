class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        array<int, 1001> stops {};
        for (auto &t : trips) {
            int num = t[0], from = t[1], to = t[2];
            stops[from] += num;
            stops[to] -= num;
        }
        int curr = 0;
        for (int num : stops) {
            curr += num;
            if (curr > capacity)
                return false;
        }
        return true;
    }
};