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
    pair<int,int> zigzag(TreeNode *root , int &mx)
    {
        if(root==NULL)
            return {-1,-1} ;
        pair<int,int> lt = zigzag(root->left,mx);
        pair<int,int> rt = zigzag(root->right,mx);
        
        
        
        pair<int,int> ans ={1+lt.second,1+rt.first};
        mx =max(mx, max(ans.first,ans.second)) ;
        return ans ;
    }
    int longestZigZag(TreeNode* root) {
        int mx = 0 ;
        pair<int,int> t = zigzag(root,mx) ;
        return mx ;
    }
};