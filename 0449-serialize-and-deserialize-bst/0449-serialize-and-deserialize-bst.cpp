/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void inorder(TreeNode* root, string &ans) {
        if(root == NULL) {
            ans += '#';
            ans += ',';
            return;
        }
        ans += to_string(root->val);
        ans += ',';
        inorder(root->left, ans);
        inorder(root->right, ans);
    }
    
    string serialize(TreeNode* root) {
        string ans = "";
        inorder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* calc(string s, int &i) {
        if(i >= s.size()) return NULL;
        if(i < s.size() and s[i] == '#') {
            i+=2;
            return NULL;
        }
        int num = 0;
        while(i < s.size() and (s[i] >= '0' and s[i] <= '9')) {
            num = num*10 + (s[i] - '0');
            i++;
        }
        i++;
        TreeNode* root = new TreeNode(num);
        root->left = calc(s, i);
        root->right = calc(s, i);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        int i = 0;
        return calc(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;