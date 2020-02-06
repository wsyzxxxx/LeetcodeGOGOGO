class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {
            return false;
        }
        
        std::vector<bool> dp(s.size(), false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (dp[i] == true) {
                for (const auto word : wordDict) {
                    if (s[i] == word[0]) {
                        bool isMatch = true;
                        int j, k;
                        for (k = i, j = 0; j < word.size() && i < s.size(); k++, j++) {
                            if (s[k] != word[j]) {
                                isMatch = false;
                                break;
                            }
                        }
                        if (isMatch && k <= s.size() && j == word.size()) {
                            if (k == s.size()) {
                                return true;
                            }
                            dp[i+j] = dp[i];
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
