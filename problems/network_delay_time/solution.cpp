/* scratch:

dijkstra to comupte shortest paths
delay time = longest path

*/

class Solution {
public:
    using Adj_list = vector<unordered_map<int, int>>;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Adj_list adj(n + 1);
        for (const vector<int> &time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u][v] = w;
        }
        vector<int> paths(n + 1, numeric_limits<int>::max());
        dijkstra(k, adj, paths);
        int ans = 0;
        for (int i = 1; i < n + 1; ++i) {
            int p = paths[i];
            if (p == numeric_limits<int>::max()) {
                return -1;
            }
            ans = max(p, ans);
        }
        return ans;
    }
    
    void dijkstra(int k, Adj_list &adj, vector<int> &paths) {
        auto cmp = [&paths](int lhs, int rhs) {
            return paths[lhs] > paths[rhs];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        q.push(k);
        paths[k] = 0;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            for (auto &edge : adj[u]) {
                int v = edge.first, w = edge.second; 
                if (paths[v] > paths[u] + w) {
                    paths[v] = paths[u] + w;
                    q.push(v);
                }
            }
        }
    }
};