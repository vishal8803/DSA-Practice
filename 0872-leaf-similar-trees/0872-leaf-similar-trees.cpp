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
    void calc(TreeNode* root, vector<int> &t){
        if(root==NULL)
            return;
        if(!root->left && !root->right)
        {
            t.push_back(root->val);
            return;
        }
        calc(root->left,t);
        calc(root->right,t);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        calc(root1,l1);
        calc(root2,l2);
        return l1==l2 ;
    }
};