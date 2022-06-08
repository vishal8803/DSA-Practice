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
    Node* clone(Node* node, map<Node*,Node*> &mp){
        
        Node* root = new Node(node->val);
        mp[node] = root;
        vector<Node*> neighbours;
        for(auto it : node->neighbors){
            if(mp.find(it)==mp.end()){
                neighbours.push_back(clone(it,mp));
            }else{
                neighbours.push_back(mp[it]);
            }
        }
        
        root->neighbors = neighbours;
        
        return root;
    }
    
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        
        if(node->neighbors.size()==0){
            Node* temp = new Node(node->val);
            return temp;
        }
        
        return clone(node,mp);
    }
};