class Solution {
public:
    bool detectCapitalUse(string word) {
        smatch m;
        return regex_match(word, m, regex {"[A-Z]*|.[a-z]*"});
    }
};