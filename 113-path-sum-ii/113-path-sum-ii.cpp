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
    void calc(TreeNode* root, int target, int curr, vector<int> temp, vector<vector<int>> &ans) {
        if(root==NULL) {
            return;
        }
        
        if(root->left==NULL && root->right==NULL) {
            curr += root->val;
            temp.push_back(root->val);
            if(curr == target) {
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(root->val);
        calc(root->left, target, curr + root->val, temp, ans);
        calc(root->right, target, curr + root->val, temp, ans);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        calc(root, targetSum, 0, {}, ans);
        return ans;
    }
};