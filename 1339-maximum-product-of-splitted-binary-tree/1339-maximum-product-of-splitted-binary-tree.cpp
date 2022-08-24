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
    int MOD = 1e9 + 7;
    void calc(TreeNode *root, long long int &totalSum)
    {
        if (root == NULL) return;

        totalSum = (totalSum + root->val);
        calc(root->left, totalSum);
        calc(root->right, totalSum);
    }

    long long int findMaxProduct(TreeNode *root, long long int &ans, long long int totalSum)
    {
        if (root == NULL)
        {
            return 0;
        }

        long long int lt = findMaxProduct(root->left, ans, totalSum);
        long long int rt = findMaxProduct(root->right, ans, totalSum);

        long long int subtreeSum = (lt + rt + root->val);

        long long int res = ((long long int) subtreeSum *(long long int)(totalSum - subtreeSum));

        if (ans < res)
        {
            ans = res;
        }

        return subtreeSum;
    }

    int maxProduct(TreeNode *root)
    {
        long long int totalSum = 0;
        calc(root, totalSum);

        long long int ans = INT_MIN;
        findMaxProduct(root, ans, totalSum);
        return ans % MOD;
    }
};