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
    TreeNode* inorderSucc(TreeNode* root){
        while(root && root->left)
            root = root->left;
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        
        if(root->val>key)
        {
            root->left = deleteNode(root->left,key);
        }else if(root->val<key)
        {
            root->right = deleteNode(root->right,key);
        }else if(root->val==key)
        {   
            if(root->left==NULL){
                
                TreeNode* rt = root->right;
                delete root;
                return rt;
            }else if(root->right==NULL){
                TreeNode* lt = root->left;
                delete root;
                return lt;
            }else{
                TreeNode* t = inorderSucc(root->right);
                root->val = t->val;
                root->right = deleteNode(root->right, t->val);
            }
        }
        
        return root;
    }
};