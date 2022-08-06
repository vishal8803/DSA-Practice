/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean calc(TreeNode root, long mx, long mn) {
        if(root==null) return true;
        if(root.val<=mn || root.val>=mx) return false;
        
        return calc(root.left,root.val,mn)&&calc(root.right,mx,root.val);
    }
    
    public boolean isValidBST(TreeNode root) {
        return calc(root, Long.MAX_VALUE, Long.MAX_VALUE+1);
    }
}