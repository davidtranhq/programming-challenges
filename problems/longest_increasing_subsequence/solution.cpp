class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq;
        for (int x : nums) {
            if (seq.empty() || x > seq.back())
                seq.push_back(x);
            else
                *lower_bound(seq.begin(), seq.end(), x) = x;
        }
        return seq.size();
    }
};