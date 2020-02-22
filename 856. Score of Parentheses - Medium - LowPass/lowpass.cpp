class Solution {
private:
    int findSum(int & i, std::string & S) {
        if (i == S.length()) {
            return 0;
        }
        
        int count = 0;
        int parentCount = 0;
        while (i < S.size()) {
            if (S[i] == '(' && S[i+1] == ')') {
                count += 1;
                i += 2;
            } else if (S[i] == '(') {
                parentCount++;
                i++;
                count += 2 * findSum(i, S);
            } else {
                parentCount--;
                if (parentCount < 0) {
                    return count;
                }
                i++;
            }
        }
        
        return count;
    }
public:
    int scoreOfParentheses(string S) {
        int n = S.length();
        
        if (n == 0) {
            return 0;
        }
        
        int i = 0;
        //std::stack<int> s;
        return findSum(i, S);
    }
};
