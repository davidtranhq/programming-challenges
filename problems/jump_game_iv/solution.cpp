class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> jumps;
        for (int i = 0; i < n; ++i) {
            jumps[arr[i]].push_back(i);
        }
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        int ans = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                if (u == n - 1)
                    return ans;
                vector<int> &next = jumps[arr[u]];
                next.push_back(u + 1);
                next.push_back(u - 1);
                for (int v : next) {
                    if (v >= 0 && v < n && !visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
                next.clear();
            }
            ++ans;
        }
        return 0;
    }
};