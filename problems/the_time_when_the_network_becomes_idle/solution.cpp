/* scratch:

compute shortest paths with bfs shortest path
earliest second = longest path * 2 if patience = 1 for all servers

time t spent active for any server (distance = d, patience = p):

if p >= 2d: t = 2d
if p < 2d:
    2d = pq + r for some integers q, r
    t = 2d + pq
*/

class Solution {
public:
    using Adj_list = unordered_map<int, unordered_set<int>>;
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        Adj_list adj;
        int n = 0;
        for (const vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].insert(v);
            adj[v].insert(u);
            n = max({n, u, v});
        }
        n += 1;
        vector<int> paths(n, -1);
        bfs(n, adj, paths);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int d = 2 * paths[i];
            int extra = (d - 1) / patience[i];
            int last = extra * patience[i];
            int time = last + d;
            ans = max(ans, time);
        }
        return ans + 1;
    }
    
    void bfs(int n, Adj_list &edges, vector<int> &paths)
    {
        queue<int> q;
        q.push(0);
        paths[0] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                if (paths[v] == -1) {
                    paths[v] = paths[u] + 1;
                    q.push(v);
                }
            }
        }
    }
};