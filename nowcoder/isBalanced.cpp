class Solution {
private:
    bool isBalanced(TreeNode * pRoot, int & depth) {
        if (pRoot == NULL) {
            depth = 0;
            return true;
        }
        
        int left, right;
        if (isBalanced(pRoot->left, left) && isBalanced(pRoot->right, right)) {
            depth = std::max(left, right) + 1;
            return (std::max(left, right) - std::min(left, right)) <= 1;
        }
        
        return false;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        return isBalanced(pRoot, depth);
    }
};
