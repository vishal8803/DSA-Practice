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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int postStart,int postEnd , int inStart ,int inEnd,map<int,int> &mp)
    {
        if(inStart>inEnd || postEnd>postStart)
            return NULL ;
        
        TreeNode *root = new TreeNode(postorder[postStart]) ;
        int posinIn = mp[root->val] ;
        int rightNodes = inEnd - posinIn ;
        root->right = build(inorder,postorder,postStart-1 , postStart-rightNodes, posinIn,inEnd,mp);
        root->left = build(inorder,postorder,postStart-rightNodes-1,postEnd,inStart,posinIn-1,mp);
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp ;
        for(int i =0 ; i<inorder.size() ; i++)
        {
            mp[inorder[i]]=i ;
        }
        TreeNode *root = build(inorder, postorder,postorder.size()-1,0 , 0 ,inorder.size()-1,mp);
        return root ;
    }
};