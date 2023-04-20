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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            int mx = INT_MIN;
            int mn = INT_MAX;
            while(size--){
                int t = q.front().second;
                TreeNode* r = q.front().first;
                q.pop();
                
                mx = max(mx,t);
                mn = min(mn,t);
                
                if(r->left){
                    q.push({r->left,(long long)2*t+1});
                }
                if(r->right){
                    q.push({r->right,(long long)2*t+2});
                }
            }
            ans = max(ans,mx-mn+1);
        }
        return ans;
    }
};