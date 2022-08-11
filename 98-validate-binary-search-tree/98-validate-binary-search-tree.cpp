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
    bool calc(TreeNode* root, long mn, long mx) {
        if(root==NULL) return true;
        
        if(root->val<=mn || root->val>=mx) return false;
        
        bool lt = calc(root->left, mn, root->val);
        bool rt = calc(root->right, root->val, mx);
        
        return lt&rt;
    }
    
    bool isValidBST(TreeNode* root) {
        return calc(root, LONG_MIN, LONG_MAX);
    }
};