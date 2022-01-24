class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(101, 0);
        for (int x : heights) {
            expected[x]++;
        }
        int res = 0;
        int h = 1;
        for (int curr : heights) {
            while (expected[h] == 0)
                h++;
            if (h != curr)
                res++;
            expected[h]--;
        }
        return res;
        
    }
};