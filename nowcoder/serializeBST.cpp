/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    void serializeCurrNode(TreeNode * root, std::string & s) {
        if (root == NULL) {
            s += "#";
            return;
        }
        
        std::ostringstream oss;
        oss << root->val << "!";
        s += oss.str();
        serializeCurrNode(root->left, s);
        serializeCurrNode(root->right, s);
    }
private:
    TreeNode * deserializeCurrNode(char ** str) {
        if (str == NULL || *str == NULL || **str == '\0') {
            return NULL;
        }
        
        if (**str == '#') {
            (*str)++;
            return NULL;
        }
        int val = 0;
        for (; **str != '!' && **str != '\0'; (*str)++) {
            val = val * 10 + **str - '0';
        }
        if (**str != '\0') {
            (*str)++;
        }
        TreeNode * root = new TreeNode(val);
        root->left = deserializeCurrNode(str);
        root->right = deserializeCurrNode(str);
        
        return root;
    }
public:
    char* Serialize(TreeNode *root) {  
        std::string s = "";
        serializeCurrNode(root, s);
        
        return strdup(s.c_str());
    }
    TreeNode* Deserialize(char *str) {
        TreeNode * root = deserializeCurrNode(&str);
        return root;
    }
};
