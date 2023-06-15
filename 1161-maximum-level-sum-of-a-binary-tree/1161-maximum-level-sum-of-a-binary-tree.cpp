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
    int maxLevelSum(TreeNode* root) {
        vector<int> levelSum; 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=0;
            int size=q.size();
            while(size--){
                TreeNode *t = q.front();
                q.pop();
                s=s+t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            levelSum.push_back(s);
        }
        int idx=-1,mx=INT_MIN;
        for(int i=0; i<levelSum.size(); i++){
            if(levelSum[i]>mx){
                mx=levelSum[i];
                idx=i+1;
            }
        }
        return idx;
    }
};