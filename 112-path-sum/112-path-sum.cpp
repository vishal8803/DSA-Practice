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
    void calc(TreeNode* root, int sum, int target, bool &ans){
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val==target)
            {
                ans = true;
            }
            return;
        }
        
        calc(root->left,sum+root->val,target,ans);
        calc(root->right,sum+root->val,target,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        calc(root,0,targetSum,ans);
        return ans;
    }
};