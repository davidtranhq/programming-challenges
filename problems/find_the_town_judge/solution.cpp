class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.size() == 0)
            return 1;
        int judge = -1;
        vector<int> in(n + 1), out(n + 1);
        for (auto &v : trust) {
            int a = v[0], b = v[1];
            ++out[a];
            ++in[b];
            if (in[b] == n - 1)
                judge = b;
        }
        if (judge == -1 || out[judge] > 0)
            return -1;
        return judge;
    }
};