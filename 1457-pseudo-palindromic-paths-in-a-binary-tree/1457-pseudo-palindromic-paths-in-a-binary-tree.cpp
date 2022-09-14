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
    void calc(TreeNode* root, map<int,int> &mp, int &count) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL) {
            mp[root->val]++;
            
                int evenCount = 0;
                int oddCount = 0;
                for(auto it : mp) {
                    int f = it.second;
                    if(f%2==0) evenCount++;
                    else oddCount++;
                }
                if(oddCount<=1) count++;
                
            
            mp[root->val]--;
            if(mp[root->val]==0) mp.erase(root->val);
            return;
        }
        mp[root->val]++;
        calc(root->left,mp,count);
        calc(root->right,mp,count);
        mp[root->val]--;
        if(mp[root->val]==0) mp.erase(root->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        int count = 0;
        calc(root, mp, count);
        return count;
    }
};