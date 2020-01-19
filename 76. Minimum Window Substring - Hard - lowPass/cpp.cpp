class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        
        std::unordered_map<char, int> required;
        int requiredCount = 0;
        for (const auto ch : t) {
            required[ch]++;
            requiredCount++;
        }
        
        std::string res = "";
        int start = 0;
        int minLen = INT_MAX;
        int minStart = -1;
        for (int i = 0; i < s.size(); i++) {
            if (required.find(s[i]) == required.end()) {
                continue;
            } else {
                if (required[s[i]] > 0) {
                    requiredCount--;
                }
                required[s[i]]--;
            }
            while (required.find(s[start]) == required.end() ||
                   required[s[start]] < 0) {
                //std::cout << "start" << start << " " << s[start] << std::endl;
                if (required.find(s[start]) != required.end()) {
                    required[s[start]]++;
                }
                start++;
            }
            //std::cout << requiredCount << std::endl;
            if (requiredCount == 0) {
                if (i - start + 1 < minLen) {
                    minLen = i - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minStart != -1) {
            res = s.substr(minStart, minLen);
        }
        return res;
    }
};
