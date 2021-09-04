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
    private List<TreeNode> generateTrees(int lowerBound, int upperBound) {
        List<TreeNode> result = new ArrayList<>();
        if (lowerBound > upperBound) {
            result.add(null);
            return result;
        }
        if (lowerBound == upperBound) {
            result.add(new TreeNode(lowerBound));
            return result;
        }
        
        for (int i = lowerBound; i <= upperBound; i++) {
            List<TreeNode> left = generateTrees(lowerBound, i-1);
            List<TreeNode> right = generateTrees(i+1, upperBound);
            
            for (TreeNode l : left) {
                for (TreeNode r : right) {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    result.add(root);
                }
            }
        }
        
        return result;
    }
    
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> result = new ArrayList<>();
        if (n < 1) {
            return result;
        }

        return generateTrees(1, n);
    }
}