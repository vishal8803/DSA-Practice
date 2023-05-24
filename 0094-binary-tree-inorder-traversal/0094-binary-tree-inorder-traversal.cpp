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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* head = root;
        while(head != NULL) {
            if(head->left==NULL) {
                ans.push_back(head->val);
                head = head->right;
            } else {
                TreeNode* t = head->left;
                while(t->right and t->right != head) {
                    t = t->right;
                }
                if(t->right == NULL) {
                    t->right = head;
                    head = head->left;
                } else {
                    t->right = NULL;
                    ans.push_back(head->val);
                    head = head->right;
                }
            }
        }
        return ans;
    }
};