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
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    bool calc(TreeNode* root, TreeNode* &ans, int ht, int curr) {
        if(curr == ht) return true;
        if(curr > ht || !root) return false;
        
        
        bool lt = calc(root->left, ans, ht, curr + 1);
        bool rt = calc(root->right, ans, ht, curr + 1);
        
        if(lt and rt) { 
            ans = root;
        }
        
        return lt | rt;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = NULL;
        calc(root, ans, height(root), 0);
        return ans;
    }
};