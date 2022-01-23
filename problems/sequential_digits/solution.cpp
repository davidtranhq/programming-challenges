class Solution {
public:
    using integral = size_t;
    vector<int> sequentialDigits(int low, int high) {
        integral nLo = 1, nHi = 1, lo = 1, hi = 1;
        while (lo * 10 <= low) {
            ++nLo;
            lo *= 10;
        }
        while (hi * 10 <= high) {
            ++nHi;
            hi *= 10;
        }
        vector<int> ans;
        for (int i = nLo; i <= nHi; ++i) {
            integral base = 0, inc = 0;
            for (integral d = i, place = 1; d >= 1; --d) {
                base += d * place;
                inc += 1 * place;
                place *= 10;
            }
            for (int j = i; j < 10 && base <= high; ++j) {
                if (base >= low)
                    ans.push_back(base);
                base += inc;
            }
        }
        return ans;
    }
};