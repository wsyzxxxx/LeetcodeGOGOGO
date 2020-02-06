class Solution {
private:
    std::unordered_map<std::string, std::vector<std::string> > mp;
    std::vector<std::string> dfs(std::string s,
                                 std::vector<std::string> & wordDict) {
        if (mp.count(s)) {
            return mp[s];
        }
        
        std::vector<std::string> res;
        for (const auto word : wordDict) {
            if (s.find(word) == 0) {
                if (word.size() == s.size()) {
                    res.push_back(s);
                } else {
                    std::vector<std::string> next = 
                        dfs(s.substr(word.size()), wordDict);
                    //std::cout << next.size() << std::endl;
                    for (const auto w : next) {
                        res.push_back(word + " " + w);
                    }
                }
            }
        }
        mp[s] = res;
        return res;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {
            return {};
        }
        
        mp.clear();
        mp[""] = {};
        return dfs(s, wordDict);
    }
};
