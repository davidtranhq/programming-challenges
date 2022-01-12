class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for (const auto &path : paths) {
            mp[path[0]] = path[1];
        }
        string curr = paths[0][0];
        while (mp[curr].size())
            curr = mp[curr];
        return curr;
    }
};