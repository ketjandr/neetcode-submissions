class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the adj list
        vector<vector<int>> adj(numCourses);
        // build the in-edges count
        vector<int> in_deg(numCourses, 0);
        for (auto &edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
            in_deg[edge[1]]++;
        }

        queue<int> q;
        int count = 0;

        // find all in_deg == 0
        for (int i = 0; i < numCourses; ++i)
            if (in_deg[i] == 0)
                q.push(i);
        
        // bfs topo sort
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            count++;
            for (int u : adj[v]) {
                if (--in_deg[u] == 0)
                    q.push(u);
            }
        }

        return count == numCourses;
    }
};
