/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int findDistToTarget(TreeNode root, TreeNode target, int k, int currDist, List<Integer> result) {
        if (root == null) {
            return currDist - 1;
        }
        
        //System.out.println(root.val + " " + currDist);
        
        if (root == target) {
            currDist = 0;
        }
        if (currDist == k) {
            result.add(root.val);
            return currDist - 1;
        } else if (currDist > k) {
            return currDist - 1;
        }
        
        if (currDist > 0) {
            findDistToTarget(root.left, target, k, currDist + 1, result);
            findDistToTarget(root.right, target, k, currDist + 1, result);
            return currDist - 1;
        }
        
        currDist = findDistToTarget(root.left, target, k, currDist < 0 ? currDist : currDist + 1, result);
        if (currDist < 0) {
            currDist = findDistToTarget(root.right, target, k, currDist, result);
            
            if (currDist >= 0) {
                findDistToTarget(root.left, target, k, currDist + 1, result);
            }
        } else {
            findDistToTarget(root.right, target, k, currDist + 1, result);
        }
        
        if (currDist == k) {
            result.add(root.val);
        }
        
        return currDist < 0 ? currDist : currDist + 1;
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> result = new ArrayList<>();
        findDistToTarget(root, target, k, -1, result);
        return result;
    }
}