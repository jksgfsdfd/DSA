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
    unordered_map<int,Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        if(visited.find(node->val)!=visited.end()){
            return visited[node->val];
        }
        Node* root = new Node(node->val);
        visited[node->val]=root;
        for(Node* neigh : node->neighbors){
            root->neighbors.push_back(cloneGraph(neigh));
        }
        return root;
    }
};
