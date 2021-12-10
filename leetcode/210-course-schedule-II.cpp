/* scratch:

topological sort

create adjacency list from prerequisites
create map of course to prequirisites left (in-degree)
order = []

add all courses with 0 prequisites to queue
while queue is empty:
    u = queue.dequeue()
    order.add(u)
    for (u, v) incident on u:
        if (in_deg[v] > 0):
            in_deg[v] -= 1
            if in_deg[v] == 0:
                queue.enqueue(v)
if order.size() < numCourses:
    cycle exists, return nothing
else
    return order
    
Space: O(V + E)
Time: O(V + E)

*/

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<unordered_map<int, bool>> edges(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto &prereq : prerequisites)
        {
            const int a = prereq[0], b = prereq[1];
            edges[b][a] = true;
            in_degree[a] += 1;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> order;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (const auto &pair : edges[u])
            {
                int v = pair.first;
                int &v_deg = in_degree[v];
                if (v_deg > 0)
                {
                    v_deg -= 1;
                    if (v_deg == 0)
                    {
                        q.push(v);
                    }
                }
            }
        }
        return order.size() < numCourses ? vector<int>() : order;
    }
};