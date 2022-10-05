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
    TreeNode* addRowInSubTree(TreeNode* root, int val, int depth, bool flag) {
        if(depth==1) {
            TreeNode* temp = new TreeNode(val);
            
            if(flag)
                temp->left = root;
            else
                temp->right = root;
            
            return temp;
        }
        
        if(root==NULL) return NULL;
        
        
        
        root->left = addRowInSubTree(root->left, val, depth - 1, true);
        root->right = addRowInSubTree(root->right, val, depth - 1, false);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        return addRowInSubTree(root, val, depth, true);
    }
};