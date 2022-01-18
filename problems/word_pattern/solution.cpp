class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss {s};
        vector<string> tokens{istream_iterator<string>{iss},
                             istream_iterator<string>{}};
        int n = pattern.size();
        if (n != tokens.size())
            return false;
        unordered_map<char, string> to_word;
        unordered_map<string, char> to_char;
        for (int i = 0; i < n; ++i) {
            char c = pattern[i];
            const string &w = tokens[i];
            if (to_word[c].empty() && !to_char[w]) {
                to_word[c] = w;
                to_char[w] = c;
            }
            else if (to_word[c] != w || to_char[w] != c)
                return false;
        }
        return true;
    }
};