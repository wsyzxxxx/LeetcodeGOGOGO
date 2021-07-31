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
    private int maxLength;
    
    Pair<Integer, Integer> findMaxLength(TreeNode root, int parent) {
        if (root == null) {
            return new Pair<>(0, 0);
        }
        
        Pair<Integer, Integer> left = findMaxLength(root.left, root.val);
        Pair<Integer, Integer> right = findMaxLength(root.right, root.val);
        
        maxLength = Math.max(maxLength, left.getKey() + right.getValue() + 1);
        maxLength = Math.max(maxLength, left.getValue() + right.getKey() + 1);
        
        Pair<Integer, Integer> res;
        if (root.val == parent + 1) {
            res = new Pair<>(Math.max(left.getKey()+1, right.getKey()+1), 0);
        } else if (root.val == parent - 1) {
            res = new Pair<>(0, Math.max(left.getValue()+1, right.getValue()+1));
        } else {
            res = new Pair<>(0, 0);
        }
        
        return res;
    }
    public int longestConsecutive(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        maxLength = 1;
        Pair<Integer, Integer> left = findMaxLength(root.left, root.val);
        Pair<Integer, Integer> right = findMaxLength(root.right, root.val);
        maxLength = Math.max(maxLength, left.getKey() + right.getValue() + 1);
        maxLength = Math.max(maxLength, left.getValue() + right.getKey() + 1);
        
        return maxLength;
    }
}