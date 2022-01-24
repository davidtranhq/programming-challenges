class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();
        for (int i = 0; i < k && n > 0; ++i) {
            bool leftEmpty = i == 0 || !flowerbed[i - 1];
            bool rightEmpty = i == k - 1 || !flowerbed[i + 1];
            if (!flowerbed[i] && leftEmpty && rightEmpty) {
                flowerbed[i++] = 1;
                --n;
            }
        }
        return n == 0;
    }
};