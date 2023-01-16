class Solution {
public:
    struct Node{
        Node* links[2];
        int count = 0;
    };
    
    Node* addDataInRoot(Node* root, int val) {
        Node* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = ((val>>i)&1);
            if(root->links[bit] == NULL) {
                root->links[bit] = new Node();
            }
            root = root->links[bit];
            root->count = root->count + 1;
        }
        
        return temp;
    }
    
    int getMaximum(Node* root, int val) {
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = ((val>>i)&1);
            if(root->links[1-bit] != NULL and root->links[1-bit]->count > 0) {
                root = root->links[1-bit];
                ans = ans | (1<<i);
            } else {
                root = root->links[bit];
            }
        }
        
        return ans;
    }
    
    Node* removeDataFromRoot(Node* root, int val) {
        Node* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = ((val>>i)&1);
            root = root->links[bit];
            root->count = root->count - 1;
        }
        
        return temp;
    }
    
    
    
    void dfs(vector<int> adj[], int node, map<int,vector<int>> &mp, Node* root, map<pair<int,int>, int> &ans) {
        root = addDataInRoot(root, node);
        
        for(auto it : mp[node]) {
            
            int val = getMaximum(root, it);
            ans[{node, it}] = val;
        }
        
        for(auto it : adj[node]) {
            dfs(adj, it, mp, root, ans);
        }
        
        root = removeDataFromRoot(root, node);
    }
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        map<int, vector<int>> mp;
        int n = parents.size();
        vector<int> adj[n];
        int root = -1;
        
        for(int i = 0; i < n; i++) {
            if(parents[i] != -1)
                adj[parents[i]].push_back(i);
            else root = i;
        }
        
        for(auto q : queries) {
            mp[q[0]].push_back(q[1]);
        }
        
        map<pair<int,int>, int> ans;
        Node* rt = new Node();
        
        dfs(adj, root, mp, rt, ans);
        vector<int> res;
        
        for(auto q : queries) {
            res.push_back(ans[{q[0], q[1]}]);
        }
        
        return res;
    }
};