class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // fact: we can fully traverse a DAG (visited all nodes), by starting from nodes w/ indegree == 0

        // build a adj list and bookkeep the indegree
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);

        for (auto &edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            adj[from].push_back(to);
            inDegree[to] += 1;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> validOrder;

        // use Kahn's traversal to topo sort
        while (!q.empty()) {
            int n = q.front();
            q.pop();

            validOrder.push_back(n);

            for (auto &neigh : adj[n]) {
                inDegree[neigh] -= 1;
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if (validOrder.size() != numCourses)
            return {};

        return validOrder;
    }
};
