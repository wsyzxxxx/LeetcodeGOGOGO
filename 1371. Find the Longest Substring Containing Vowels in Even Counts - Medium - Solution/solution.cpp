class Solution {
private:
    int states[32];
public:
    int findTheLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        
        std::memset(states, -1, sizeof(states));
        
        int curr = 0;
        int maxCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                curr ^= 1;
            }
            if (s[i] == 'e') {
                curr ^= 2;
            }
            if (s[i] == 'i') {
                curr ^= 4;
            }
            if (s[i] == 'o') {
                curr ^= 8;
            }
            if (s[i] == 'u') {
                curr ^= 16;
            }
            
            if (states[curr] >= 0 || curr == 0) {
                maxCount = std::max(maxCount, i - states[curr]);
            } else {
                states[curr] = i;
            }
        }
        
        return maxCount;
    }
};
