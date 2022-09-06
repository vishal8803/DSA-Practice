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
    bool calc(TreeNode* &root) {
        if(root==NULL) return false;
        
        bool lt = calc(root->left);
        bool rt = calc(root->right);
        
        if(lt==false) {
            root->left = NULL; 
        } 
        
        if(rt==false) {
            root->right = NULL;
        }
        
        return (lt || rt || (root->val==1));
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool res = calc(root);
        if(!res) return NULL;
        return root;
    }
};