class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]);
        }
        return ans;
    }
};