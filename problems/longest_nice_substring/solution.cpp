/* scratch:

divide and conquer: O(n)

find not-nice character
split string into s1 and s2, excluding not-nice character
solve recursively for s1 and s2
return bigger of s1 and s2
    
*/

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if (n < 2)
            return "";
        unordered_set<char> chs(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (chs.find(tolower(c)) != chs.end() && chs.find(toupper(c)) != chs.end())
                continue;
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i + 1, n - i - 1));
            return s2.size() > s1.size() ? s2 : s1;
        }
        return s;
    }
};