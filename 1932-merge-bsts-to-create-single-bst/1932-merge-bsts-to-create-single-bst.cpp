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
    void merge(TreeNode* root, map<int, TreeNode*> &mp) {
        if(root == NULL) return;
        
        
        if(mp.find(root->val) != mp.end()) {
            TreeNode* temp = mp[root->val];
            root->left = temp->left;
            root->right = temp->right;
            mp.erase(root->val);
        }
        
        merge(root->left, mp);
        merge(root->right, mp);
    }
    
    bool calc(TreeNode* root, long mn, long mx) {
        if(root==NULL) return true;
        
        if(root->val<=mn || root->val>=mx) return false;
        
        bool lt = calc(root->left, mn, root->val);
        bool rt = calc(root->right, root->val, mx);
        
        return lt&rt;
    }
    
    bool isValidBST(TreeNode* root) {
        return calc(root, LONG_MIN, LONG_MAX);
    }
    
    void dfs(TreeNode* tree, set<int> &leafs) {
        if(tree == NULL) return;
        if(tree->left == NULL and tree->right == NULL) {
            leafs.insert(tree->val);
            return;
        }
        dfs(tree->left, leafs);
        dfs(tree->right, leafs);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if(trees.size() == 1) return trees[0];
        set<int> leafs;
        for(TreeNode* Tree : trees) {
            dfs(Tree, leafs);
        }
        
        TreeNode* root = NULL;
        for(TreeNode* Tree : trees) {
            if(leafs.find(Tree->val) == leafs.end()) {
                root = Tree;
                break;
            }
        }
        
        if(root == NULL) return NULL;
        
        map<int, TreeNode*> mp;
        for(int i = 0; i < trees.size(); i++) {
            if(root == trees[i]) continue;
            mp[trees[i]->val] = trees[i];
        }
        
        merge(root, mp);
        
        if(isValidBST(root) and mp.size() == 0) return root;
        return NULL;
    }
};