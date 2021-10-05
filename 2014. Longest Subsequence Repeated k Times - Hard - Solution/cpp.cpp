class Solution {
private:
    bool possible(const std::string & s, int k, const std::string & curr) {
        int count = 0;
        int index = 0;
        for (int i = 0; i < s.length() && count < k; i++) {
            if (curr[index] == s[i]) {
                index++;
            }
            if (index == curr.size()) {
                index = 0;
                count++;
            }
            
            if ((k - count) * (int)curr.length() - index - 1 > (int)s.length() - i) {
                return false;
            }
        }
        
        return count == k;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        std::vector<std::vector<std::string>> results(9);
        results[0].push_back("");
        for (int i = 1; i <= s.length()/k; i++) {
            for (const std::string & last : results[i-1]) {
                for (char c = 'z'; c >= 'a'; c--) {
                    std::string curr = last + c;
                    if (possible(s, k, curr)) {
                        results[i].push_back(curr);
                    }
                }
            }
        }
        
        for (int i = s.length()/k; i >= 0; i--) {
            if (!results[i].empty()) {
                return results[i][0];
            }
        }
        return "";
    }
};