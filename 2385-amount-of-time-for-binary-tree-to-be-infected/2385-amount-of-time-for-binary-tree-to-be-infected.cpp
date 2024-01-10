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
    void inorder(TreeNode* root, map<TreeNode*, TreeNode*> &mp, TreeNode* &target, int data) {
        if(root==NULL) return;
        
        if(root->val==data) target = root;
        
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        
        inorder(root->left, mp,target,data);
        inorder(root->right, mp, target, data);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;
        TreeNode* st;
        set<TreeNode*> vis;
        
        inorder(root, mp, st, start);
        
        queue<TreeNode*> q;
        q.push(st);
        vis.insert(st);
        
        int count = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            bool flag = false;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && vis.find(node->left)==vis.end()) {
                    q.push(node->left);
                    flag = true;
                    vis.insert(node->left);
                }
                
                if(node->right && vis.find(node->right)==vis.end()) {
                    q.push(node->right);
                    flag = true;
                    vis.insert(node->right);
                }
                
                if(mp.find(node) != mp.end() && vis.find(mp[node])==vis.end()) {
                    q.push(mp[node]);
                    flag = true;
                    vis.insert(mp[node]);
                }
            }
            if(flag) count++;
        }
        return count;
    }
};