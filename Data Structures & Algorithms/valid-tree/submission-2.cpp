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

        // check if theyre already connected
        if (root1 == root2)
            return false; // cycle detected
        
        // if not connected
        parent[root1] = root2;
        return true;
    }
        
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);

        // ret true if is a tree. a tree has:
        // - no cycles
        // - E = V-1
        for (auto &edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            if (!unite(n1, n2, parent))
                return false; // cycle detected
        }

        // int root = find(0, parent);
        // for (int i = 0; i < n; ++i) {
        //     if (find(i, parent) != root)
        //         return false; // not connected
        // }

        return true;
    }
};
