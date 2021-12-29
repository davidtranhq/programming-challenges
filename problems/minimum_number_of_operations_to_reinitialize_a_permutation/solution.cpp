class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n), A(n);
        iota(perm.begin(), perm.end(), 0);
        int ans = 0;
        bool solved = false;
        while (!solved) {
            solved = true;
            for (int i = 0; i < n; ++i) {
                A[i] = i % 2 == 0
                    ? perm[i / 2]
                    : perm[n / 2 + (i - 1) / 2];
                if (A[i] != i)
                    solved = false;
            }
            perm = A;
            ++ans;
        }
        return ans;
    }
};