class Solution {
public:
    void dfsComponent(int n, std::vector<vector<int>> &adj, std::unordered_set<int> &visited) {
        visited.insert(n); // mark node visited
        for (auto &neighbor : adj[n]) {
            if (visited.contains(neighbor))
                continue;
    
            dfsComponent(neighbor, adj, visited);
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // build an adjacency list, assume edges arent duplicated
        std::vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // keep track of visited nodes
        std::unordered_set<int> visited;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // ret # of connected graphs
            if (visited.contains(i))
                continue;
            dfsComponent(i, adj, visited);
            ++count;
        }

        return count;
    }
};
