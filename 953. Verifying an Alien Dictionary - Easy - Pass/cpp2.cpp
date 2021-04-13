class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::unordered_map<int, char> mp;
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            bool isOrdered = false;
            for (int j = 0; j < words[i].size() && j < words[i-1].size(); j++) {
                if (words[i][j] != words[i-1][j]) {
                    if (mp[words[i-1][j]] > mp[words[i][j]]) {
                        return false;
                    }
                    isOrdered = true;
                    break;
                }
            }
            if (!isOrdered && words[i-1].size() > words[i].size()) {
                return false;
            }
        }
        
        return true;
    }
};