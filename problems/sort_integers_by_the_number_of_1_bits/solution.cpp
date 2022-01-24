class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        array<int, 16> ones = {
            0, 1, 1, 2,
            1, 2, 2, 3,
            1, 2, 2, 3,
            2, 3, 3, 4
        };
        auto cmp = [this, &ones](int lhs, int rhs) {
            int left_ones = total_ones(lhs, ones);
            int right_ones = total_ones(rhs, ones);
            if (left_ones == right_ones)
                return lhs < rhs;
            else
                return left_ones < right_ones;
        };
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
    
    int total_ones(int x, const array<int, 16> &ones)
    {
        return ones[x & 0xf]
            + ones[(x >> 4) & 0xf]
            + ones[(x >> 8) & 0xf]
            + ones[(x >> 12) & 0xf];
    }
};