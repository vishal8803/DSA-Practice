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
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
    vector<TreeNode*> helper(int n)
    {
        if(n==1)
        {
            vector<TreeNode*> ans ;
            ans.push_back(new TreeNode(0));
            return ans ;
        }
        vector<TreeNode*> ans ;
        for(int i=1 ; i<n; i+=2)
        {
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n-i-1);
            
            for(TreeNode* lt:left)
            {
                for(TreeNode* rt:right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left=lt;
                    root->right=rt;
                    ans.push_back(root);
                }
            }
        }
        return ans ;
    }
};