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
    bool isPresent(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2)
            return true;
        
        if(!n1 || !n2)
            return false;
        
        return (n1->val==n2->val) && (isPresent(n1->left,n2->left)) && (isPresent(n1->right,n2->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)
            return true;
        
        if(!root || !subRoot)
            return false;
        
        bool lt = isSubtree(root->left,subRoot);
        bool rt = isSubtree(root->right,subRoot);
        
        return lt || rt || isPresent(root,subRoot);
    }
};