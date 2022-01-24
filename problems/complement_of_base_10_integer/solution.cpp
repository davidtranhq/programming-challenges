class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 2;
        int x = n;
        while (x > 1) {
            x >>= 1;
            mask <<= 1;
        }
        return (~n & (mask - 1));
    }
};