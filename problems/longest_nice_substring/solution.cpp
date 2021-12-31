/* scratch:
    hashtable of (letter, index)
    
    Y a z a A a y
   |  |
        
    
*/

class Solution {
public:
    string longestNiceSubstring(string s) {
        unordered_set<char> chs, missing;
        int n = s.size();
        string longest;
        auto cmp = [](const string &s1, const string &s2) {
            return s1.length() < s2.length();
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                char c = s[j];
                char opp = islower(c) ? toupper(c) : tolower(c);
                if (chs.find(opp) == chs.end()) {
                    missing.insert(opp);
                }
                missing.erase(c);
                if (missing.size() == 0)
                    longest = max(longest, s.substr(i, j - i + 1), cmp);
                chs.insert(c);
            }
            chs.clear();
            missing.clear();
        }
        return longest;
    }
};