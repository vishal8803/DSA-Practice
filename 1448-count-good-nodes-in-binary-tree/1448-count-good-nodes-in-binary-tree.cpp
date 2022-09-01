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
    int calc(TreeNode* root, int prev) {
        if(root==NULL) {
            return 0;
        }
        int ans = 0;
        
        if(root->val >= prev) ans += 1;
        
        ans += calc(root->left, max(root->val,prev));
        ans += calc(root->right, max(root->val,prev));
        
        return ans;
        
    }
    int goodNodes(TreeNode* root) {
        return calc(root, INT_MIN);
    }
};