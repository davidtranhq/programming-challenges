class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> list;
        dfs(0, list, res, s);
        return res;
    }
    
    void dfs(int start, vector<string> &list, vector<vector<string>> &res, const string &s) {
        int n = s.length();
        if (start >= n)
            res.push_back(list);
        for (int end = start; end < n; ++end) {
            if (!isPalindrome(start, end, s))
                continue;
            list.push_back(s.substr(start, end - start + 1));
            dfs(end + 1, list, res, s);
            list.pop_back();
        }
    }
    
    bool isPalindrome(int start, int end, const string &s) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};