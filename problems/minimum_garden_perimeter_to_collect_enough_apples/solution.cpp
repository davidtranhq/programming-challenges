/* scratch:

one quadrant (excluding cardinals):
    2 * L (1 + 2 + 3 + ... + L) = 2L (L(L + 1)) / 2 = L^2(L + 1)
    
    L^2(L + 1) * 4 + (L^2(L + 1) / 2) * 4 = 6L^2(L + 1)
    
apples = 6L^2(L + 1)
6L^3 + 6L^2 - apples = 0

*/

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long a = 0, l = 0;
        while (a < neededApples) {
            ++l;
            a = 2 * l * (l + 1) * (2 * l + 1);
        }
        return l * 8;
    }
};