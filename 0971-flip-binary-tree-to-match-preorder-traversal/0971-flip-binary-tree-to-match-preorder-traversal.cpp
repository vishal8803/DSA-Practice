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
    bool calc(TreeNode* root, vector<int> &voyage, int &i, vector<int> &ans) {
        if(root == NULL) return true;
        
        if(root->val != voyage[i]) {
            return false;
        } else i++;
        
        if(root->left != NULL and root->left->val != voyage[i]) {
            ans.push_back(root->val);
            return calc(root->right, voyage, i, ans) and calc(root->left, voyage, i, ans);
        }
        return calc(root->left, voyage, i, ans) and calc(root->right, voyage, i, ans);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        vector<int> ans;
        int res = calc(root, voyage, i, ans);
        if(res) return ans;
        return {-1};
    }
};