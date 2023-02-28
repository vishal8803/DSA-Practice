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
    string calc(TreeNode* root, map<string,TreeNode*> &mp, map<string,TreeNode*> &an){
        if(root == NULL){
            return "X";
        }
        
        string left = calc(root->left,mp,an);
        string right = calc(root->right,mp,an);
        string ans = to_string(root->val)+","+left+","+right+",";
        // cout<<ans<<endl;
        if(mp.find(ans)!= mp.end()){
            an[ans] = root;
        }else{
            mp[ans]=root;
        }
        return ans;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,TreeNode*> mp;
        map<string,TreeNode*> st;
        string t = calc(root, mp, st);
        vector<TreeNode*> ans;
        for(auto it = st.begin(); it != st.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};