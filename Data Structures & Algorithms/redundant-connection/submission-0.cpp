class Solution {
public:
    int find(int n, vector<int>& parent) {
        if (parent[n] == n)
            return n;
        
        parent[n] = find(parent[n], parent);
        return parent[n];
    }

    bool unite(int n1, int n2, vector<int>& parent) {
        int root1 = find(n1, parent);
        int root2 = find(n2, parent);

        if (root1 == root2)
            return false; // this must be a cycle
        
        // attach n2 to n1
        parent[root2] = root1;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // we need to find a cycle, and remove any edge from that cycle
        vector<int> parent(edges.size() + 1);
        std::iota(parent.begin(), parent.end(), 0);

        for (auto &edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            if (!unite(n1, n2, parent))
                return edge; // must be a cycle
        }

        return {};
    }
};
