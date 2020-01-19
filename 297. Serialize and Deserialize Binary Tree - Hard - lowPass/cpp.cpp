/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//use ',' to separate the nodes
//save null pointers as '#'
class Codec {
private:
    void serialize(TreeNode * root, std::string & res) {
        if (root == nullptr) {
            res += "#,";
            return;
        }
        
        std::ostringstream oss;
        oss << root->val << ",";
        res += oss.str();
        serialize(root->left, res);
        serialize(root->right, res);
    }
    TreeNode * deserialize(std::string & data, int & currPos) {
        if (currPos >= data.size()) {
            return nullptr;
        }
        if (data[currPos] == '#') {
            currPos += 2;
            return nullptr;
        }
        
        bool flag = false;
        if (data[currPos] == '-') {
            //std::cout << data.substr(currPos) << std::endl;
            flag = true;
            currPos++;
        }
        int val = 0;
        while (data[currPos] != ',') {
            val = val * 10 + data[currPos++] - '0';
        }
        if (flag) {
            val = -val;
        }
        currPos++;
        TreeNode * root = new TreeNode(val);
        root->left = deserialize(data, currPos);
        root->right = deserialize(data, currPos);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string res = "";
        serialize(root, res);
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        
        int pos = 0;
        return deserialize(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
