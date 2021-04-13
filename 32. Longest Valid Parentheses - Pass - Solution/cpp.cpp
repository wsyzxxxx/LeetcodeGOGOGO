int dp[30005];

class Solution {
public:
    int longestValidParentheses(string s) {
        std::memset(dp, 0, sizeof(dp));
        std::stack<int> st;
        int count = 0;
        int maxSize = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int size = i - st.top() + 1 + dp[st.top()];
                    maxSize = std::max(maxSize, size);
                    dp[i+1] = size;
                    st.pop();
                }
            }
        }
        return maxSize;
    }
};