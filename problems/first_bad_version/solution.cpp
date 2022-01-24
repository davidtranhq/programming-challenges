// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool bad = isBadVersion(mid);
            if (bad)
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};