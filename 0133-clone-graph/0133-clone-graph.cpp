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
    unordered_map<Node*,Node*> mp;
    Node* dfs(Node* node){
        if(!node) return NULL;
        if(mp.count(node)) return mp[node];

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for(Node* i : node->neighbors){

            newNode->neighbors.push_back(dfs(i));
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
      
       return dfs(node);
    }
};