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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int,multiset<int>>> mp;
        
        queue<pair<int,TreeNode*>> q;
        q.push({0, root});
        int height = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int level = q.front().first;
                TreeNode* node = q.front().second;
                q.pop();
                mp[level][height].insert(node->val);
                if(node->left) {
                    q.push({level-1,node->left});
                }
                if(node->right) {
                    q.push({level+1,node->right});
                }
            }
            height++;
        }
        
        for(auto it : mp) {
            vector<int> temp;
            for(auto it2 : it.second) {
                for(auto it3 : it2.second) {
                    temp.push_back(it3);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};