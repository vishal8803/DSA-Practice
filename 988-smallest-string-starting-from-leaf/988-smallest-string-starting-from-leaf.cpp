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
    void calc(TreeNode* root, string temp, string &ans) {
        if(root==NULL) {
            
            reverse(temp.begin(), temp.end());
            if(ans=="") ans = temp;
            else {
                if(ans > temp) ans = temp;
            }
            return;
        }
        temp += ('a' + root->val);
        
        if(root->left!=NULL && root->right!=NULL) {
            calc(root->left,temp, ans);
            calc(root->right,temp, ans);
        } else if(root->left) {
            calc(root->left,temp, ans);
        } else {
            calc(root->right,temp, ans);
        }
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        calc(root,"",ans);
        return ans;
    }
};