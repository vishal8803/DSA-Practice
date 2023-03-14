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
    void getRootToLeafPath(TreeNode* root , int s , int &sum)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(!root->left && !root->right)
        {
            sum=sum + s*10 + root->val ;
            return ;
        }
        getRootToLeafPath(root->left , s*10+root->val,sum);
        getRootToLeafPath(root->right , s*10+root->val,sum);
    }
    int sumNumbers(TreeNode* root) 
    {
        int s =0 ;
        getRootToLeafPath(root,0,s) ;
        return s ;
    }
};