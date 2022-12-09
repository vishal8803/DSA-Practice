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
    void maxDiff(TreeNode* root, int mn, int mx, int &ans){
        if(root == NULL){
            return ;
        }
        
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        ans = max(ans,abs(mx-mn));
        maxDiff(root->left,mn,mx,ans);
        maxDiff(root->right,mn,mx,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        maxDiff(root,INT_MAX,INT_MIN,ans);
        return ans;
    }
};