/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, map<TreeNode*, TreeNode*> &mp) {
        if(root == NULL) return;
        
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        
        dfs(root->left, mp);
        dfs(root->right, mp);
    }
    
    void findPair(TreeNode* root, map<TreeNode*, TreeNode*> &mp, int &ans, int distance, map<TreeNode*,bool> &visited) {
        if(root == NULL || distance < 0 || visited[root]) return;
        // cout<<root->val<<" "<<distance<<endl;
        if(root->left == NULL and root->right == NULL and distance >= 0) {
            // cout<<"Special "<<root->val<<" "<<distance<<endl;
            ans++;
        }
        visited[root] = true;
        findPair(root->left, mp, ans, distance - 1, visited);
        findPair(root->right, mp, ans, distance - 1, visited);
        findPair(mp[root], mp, ans, distance - 1, visited);
    }
    
    void calc(TreeNode* root, map<TreeNode*, TreeNode*> &mp, int &ans, int distance) {
        if(root == NULL) return;
        
        if(root->left == NULL and root->right == NULL) {
            map<TreeNode*,bool> vis;
            // cout<<root->val<<"-> ";
            findPair(root, mp, ans, distance, vis);
            ans--;
        }
        
        calc(root->left, mp, ans, distance);
        calc(root->right, mp, ans, distance);
    }
    
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*,TreeNode*> parent;
        dfs(root, parent);
        int ans = 0;
        calc(root, parent, ans, distance);
        
        return ans/2;
    }
};