class Solution {
private:
    std::string sortStr(std::string & s) {
        int chars[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            chars[s[i] - 'a']++;
        }
        
        std::string res;
        for (int i = 0; i < 26; i++) {
            while (chars[i] != 0) {
                chars[i]--;
                res.push_back(i + 'a');
            }
        }
        
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string> > res;
        if (strs.empty()) {
            return res;
        }
        
        std::unordered_map<std::string, std::vector<std::string> > resMap;
        
        for (int i = 0; i < strs.size(); i++) {
            std::string s = sortStr(strs[i]);
            resMap[s].push_back(strs[i]);
        }
        
        for (auto item : resMap) {
            res.push_back(item.second);
        }
        
        return res;
    }
};
