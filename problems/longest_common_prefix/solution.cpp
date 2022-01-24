class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unsigned long k = 200;
        for (const string &s : strs) {
            k = min(k, s.size());
        }
        for (int i = 0; i < k; ++i) {
            char c = strs[0][i];
            for (const string &s : strs) {
                if (c != s[i])
                    return s.substr(0, i);
            }
        }
        return strs[0].substr(0, k);
    }
};