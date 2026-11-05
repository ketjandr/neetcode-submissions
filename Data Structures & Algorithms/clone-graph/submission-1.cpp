/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> mp;
        return cloneGraphWorker(node, mp);
    }
private:
    Node* cloneGraphWorker(Node* node, unordered_map<int, Node*> &mp) {
        Node* n = new Node(node->val);
        mp[node->val] = n;

        for (auto &neigh : node->neighbors) {
            // visited
            if (mp.contains(neigh->val)) {
                n->neighbors.push_back(mp[neigh->val]);
                continue;
            }

            // not visited
            n->neighbors.push_back(cloneGraphWorker(neigh, mp));
        }

        return n;
    }

};
