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
    void calc(TreeNode* root, TreeNode* &prev, int &diff){
        if(root==NULL){
            return;
        }
        calc(root->left,prev,diff);
        
        if(prev != NULL){
            diff = min(diff, root->val-prev->val);
        }
        prev = root;
        calc(root->right,prev,diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev = NULL;
        calc(root,prev,diff);
        return diff;
    }
};