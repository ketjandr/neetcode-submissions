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
    Node* dfsClone(Node* n, std::unordered_map<Node*, Node*>& nmap) {
        if (!n) return nullptr;

        Node* copy = new Node(n->val);

        // insert the og -> copy node ptr for bookepping if not already inserted
        auto [it, inserted] = nmap.try_emplace(n, copy);

        for (auto neighbor : n->neighbors) {
            Node* copiedNbor;
            if (!nmap.contains(neighbor)) {
                copiedNbor = dfsClone(neighbor, nmap);
            } else {
                copiedNbor = nmap[neighbor];
            }

            copy->neighbors.push_back(copiedNbor);
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {

        // hashmap to keep track of original ptr -> copy ptr
        std::unordered_map<Node*, Node*> nodeMap;

        // ret the cloned graph
        return dfsClone(node, nodeMap);
    }
};
