class Solution {
private:
    void checkParentese(std::vector<std::string> & res, 
                        int openCount, int closeCount, int n,
                        std::string currStr) {
        if (openCount == closeCount && openCount == n) {
            res.push_back(currStr);
            return;
        }
        
        if (openCount > n || closeCount > n || closeCount > openCount) {
            return;
        }
        checkParentese(res, openCount+1, closeCount, n, currStr + "(");
        checkParentese(res, openCount, closeCount+1, n, currStr + ")");
    }
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        if (n == 0) {
            return res;
        }
        checkParentese(res, 0, 0, n, "");
        return res;
    }
};
