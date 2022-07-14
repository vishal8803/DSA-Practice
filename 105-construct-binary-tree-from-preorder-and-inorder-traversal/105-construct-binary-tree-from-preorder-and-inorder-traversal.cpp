/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* calc(vector<int> &inorder, vector<int> &preorder, int preSt, int preEnd, int inSt, int inEnd, map< int, int> &mp)
        {
            if (preSt > preEnd || inSt > inEnd)
            {
                return NULL;
            }

            int pos = mp[preorder[preSt]];
            int numofnodeinleft = pos - inSt;
            TreeNode *root = new TreeNode(preorder[preSt]);
            root->left = calc(inorder, preorder, preSt + 1, preSt + numofnodeinleft, inSt, pos - 1, mp);
            root->right = calc(inorder, preorder, preSt + 1 + numofnodeinleft, preEnd, pos + 1, inEnd, mp);
            return root;
        }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = calc(inorder, preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, mp);
        return root;
    }
};