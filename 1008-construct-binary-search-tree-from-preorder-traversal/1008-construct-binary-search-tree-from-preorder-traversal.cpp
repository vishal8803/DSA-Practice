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
    TreeNode* construct(vector<int> &preorder, int mx, int mn, int &i){
        if(i>=preorder.size())
            return NULL;
        
        TreeNode* root = NULL;
        if(preorder[i] > mn && preorder[i] < mx){
            root = new TreeNode(preorder[i]);
            i++;
            if(i<preorder.size())
                root->left = construct(preorder,root->val,mn,i);
            
            if(i<preorder.size())
                root->right = construct(preorder,mx,root->val,i);
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return construct(preorder,INT_MAX,INT_MIN,i);
    }
};