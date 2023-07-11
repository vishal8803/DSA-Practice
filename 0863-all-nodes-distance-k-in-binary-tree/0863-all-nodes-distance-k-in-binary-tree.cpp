/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNode(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){
        if(root==NULL)
            return false;
        
        if(root==target){
            path.push_back(root);
            return true;
        }
        
        if(rootToNode(root->left,target,path)){
            path.push_back(root);
            return true;
        }
        if(rootToNode(root->right,target,path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
    
    void kNodeDown(TreeNode* root, int k, TreeNode* blocker, vector<int> &ans){
        if(root==NULL || k<0 || root==blocker)
            return;
        
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        kNodeDown(root->left,k-1,blocker,ans);
        kNodeDown(root->right,k-1,blocker,ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        rootToNode(root,target,path);
        vector<int> ans;
        
        for(int i = 0; i < path.size(); i++){
            if(i==0){
                kNodeDown(path[i],k-i,NULL,ans);
            }else{
                kNodeDown(path[i],k-i,path[i-1],ans);
            }
        }
        return ans;
    }
};