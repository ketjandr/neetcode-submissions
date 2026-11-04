class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        
        vector<vector<int>> adj(n);
        // build adj list
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> parent(n, -1);
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        // bfs from the root node
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            

            for (auto &u : adj[v]) {
                // already visited edge
                if (parent[v] == u)
                    continue;

                // cycle
                if (visited[u])
                    return false;
                
                parent[u] = v;
                visited[u] = true;
                q.push(u);
            }
        }

        return count(visited.begin(), visited.end(), true) == n;

    }
};
