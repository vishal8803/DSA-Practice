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
    bool calc(TreeNode* lt, TreeNode* rt){
        if(!lt && !rt)
            return true;
        
        if((lt && !rt) || (!lt && rt))
            return false;
        
        if(lt->val != rt->val)
            return false;
        
        return calc(lt->left,rt->right) && calc(lt->right, rt->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        
        return calc(root->left,root->right);
        
    }
};