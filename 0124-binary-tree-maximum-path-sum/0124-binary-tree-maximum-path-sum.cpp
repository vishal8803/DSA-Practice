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
    int maxSum(TreeNode* root, int &ans){
        if(root==NULL)
            return 0;
        
        int lt = maxSum(root->left,ans);
        int rt = maxSum(root->right,ans);
        
        if(lt<0)lt=0;
        if(rt<0)rt=0;
        
        ans = max(ans,lt+rt+root->val);
        return root->val + max(lt,rt);
        
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root,ans);
        return ans;
    }
};