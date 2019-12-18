/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    void findPath(TreeNode* curr,
                  int expectNumber,
                  int currSum,
                  std::vector<int> & currPath,
                  std::vector<std::vector<int> > & res) {
        if (curr == NULL) {
            return;
        }
        
        currSum += curr->val;
        currPath.push_back(curr->val);
        if (curr->left == NULL &&
            curr->right == NULL &&
            currSum == expectNumber) {
            res.push_back(currPath);
        } else {
            findPath(curr->left, expectNumber, currSum, currPath, res);
            findPath(curr->right, expectNumber, currSum, currPath, res);
        }
        currPath.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        std::vector<std::vector<int> > res;
        if (root == NULL) {
            return res;
        }
        std::vector<int> currPath;
        findPath(root, expectNumber, 0, currPath, res);
        
        return res;
    }
};
