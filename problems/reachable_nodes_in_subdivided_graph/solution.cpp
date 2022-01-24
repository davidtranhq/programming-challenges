/* scratch:

get shortest paths with dijkstra
for each node u:
    if u.path < max:
        count += 1
    for each incident edge (u, v):
        if (max - u.path) + (max - v.path) > weight(u, v):
            count += weight(u, v) / 2
        else:
            count += max - u.path
        
dijkstra(edges):
    initialize each node.path to infinity
    intiialize min priority queue
    queue.push(0)
    while queue is not empty:
        u = queue.pop()
        for each incident edge (u, v):
            if (u.path + weight(u, v) < v.path):
                v.path = u.path + weight(u, v)
                queue.push(v)
                

*/

struct Edge {
    int v;
    int weight;
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n)
    {
        // build adjacency list for edges
        int E = edges.size();
        vector<vector<Edge>> adj(E);
        for (int i = 0; i < E; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight + 1});
            adj[v].push_back({u, weight + 1});
        }
        vector<int> paths(n);
        dijkstra(adj, n, paths);
        int ans = 0;
        for (int u = 0; u < n; ++u) {
            if (paths[u] <= maxMoves)
                ans += 1;
        }
        for (auto &e : edges) {
            // edge can be crossed completely
            int u = e[0], v = e[1], weight = e[2];
            int u_left = max(0, maxMoves - paths[u]);
            int v_left = max(0, maxMoves - paths[v]);
            if (u_left + v_left >= weight) {
                ans += weight;
            } else {
                ans += u_left + v_left;
            }
        }
        return ans;
    }
    
    void dijkstra(vector<vector<Edge>> &edges, int n, vector<int> &paths)
    {
        for (int &path : paths) {
            path = numeric_limits<int>::max();
        }
        // priority queue based on node path
        auto cmp = [&](int a, int b) { return paths[a] > paths[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        paths[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            for (Edge &e : edges[u]) {
                int v = e.v;
                if (paths[u] + e.weight < paths[v]) {
                    paths[v] = paths[u] + e.weight;
                    q.push(v);
                }
            }
        }
        
    }
};