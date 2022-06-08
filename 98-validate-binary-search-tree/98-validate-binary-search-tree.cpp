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
    bool calc(TreeNode* root, long long mx, long long mn){
        if(root==NULL)
            return true;
        
        if(root->val >= mx || root->val <= mn)
            return false;
        
        if(root->left==NULL && root->right==NULL)
            return true;
        
        bool lt = calc(root->left,root->val,mn);
        bool rt = calc(root->right,mx,root->val);
        
        return lt&rt;
    }
    bool isValidBST(TreeNode* root) {
        
        return calc(root,LONG_MAX,LONG_MIN);
    }
};