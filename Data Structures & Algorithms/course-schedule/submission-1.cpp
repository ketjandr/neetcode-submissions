class Solution {
public:
    // helper to determine if DG has a cycle
    bool detectCycle(int n, vector<vector<int>> &adj, unordered_set<int>& currPath, unordered_set<int>& visited) {
        if (currPath.contains(n))
            return true;
        
        if (visited.contains(n))
            return false;

        currPath.insert(n);
        
        // dfs through the other stuff
        for (auto &node : adj[n]) {
            if (detectCycle(node, adj, currPath, visited))
                return true;
        }

        currPath.erase(n);
        visited.insert(n);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // node = a course # [0, 1, ..., numCourses - 1]
        // directed edge = [b, a], b -> a (inverse of prerequisites)
        
        vector<vector<int>> adj(numCourses); // adj list

        // build the DG as a directed adj list
        for (auto &edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            adj[from].push_back(to);
        }

        unordered_set<int> currPath;
        unordered_set<int> visited;

        // a cycle in the DG means a course is impossible to traverse
        for (int i = 0; i < numCourses; ++i) {
            // we can only enter the DG from nodes that have no incoming edges
            if (!visited.contains(i)) {
                if (detectCycle(i, adj, currPath, visited))
                    return false;
            }
        }
            
        return true;
    }
};
