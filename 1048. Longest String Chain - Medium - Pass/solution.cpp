bool cmp(const std::string & a, const std::string & b) {
    return a.size() < b.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        std::sort(words.begin(), words.end(), cmp);
        std::unordered_map<std::string, int> mp;
        
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int best = 0;
            for (int j = 0; j < words[i].size(); j++) {
                std::string temp = words[i].substr(0, j) + words[i].substr(j+1);
                best = std::max(best, mp[temp] + 1);
            }
            mp[words[i]] = best;
            maxLen = std::max(best, maxLen);
        }
        
        return maxLen;
    }
};
