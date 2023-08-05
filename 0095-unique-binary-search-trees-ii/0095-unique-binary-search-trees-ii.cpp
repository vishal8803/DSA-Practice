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
    vector<TreeNode*> helper(int st, int end){
        
        if(st>end){
            vector<TreeNode*> t;
            t.push_back(NULL);
            return t;
        }
        
        vector<TreeNode*> ans;
        for(int i = st; i<=end; i++){
            vector<TreeNode*> lt = helper(st,i-1);
            vector<TreeNode*> rt = helper(i+1,end);
            
            
            for(TreeNode* k : lt){
                for(TreeNode* j : rt){
                    TreeNode* root = new TreeNode(i);
                    root->left = k;
                    root->right = j;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};