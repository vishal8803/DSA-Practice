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
    void inorder(TreeNode* root, vector<int> &order){
        if(root==NULL)
            return;
        
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> order;
        inorder(root,order);
        int i=0,j=order.size()-1;
        while(i<j)
        {
            int target = order[i]+order[j];
            if(target==k)
                return true;
            else if(target>k)
                j--;
            else
                i++;
        }
        return false;
    }
};