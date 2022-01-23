class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0, i = 0, j = n - 1;
        while (i < j) {
            int a = height[i], b = height[j];
            ans = max(ans, (j - i) * min(a, b));
            if (a < b)
                ++i;
            else
                --j;
        }
        return ans;
    }
};