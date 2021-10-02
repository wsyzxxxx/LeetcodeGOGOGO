class WordDistance {
private:
    std::unordered_map<std::string, std::vector<int>> mp;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            mp[wordsDict[i]].push_back(i);
        }
        
        
    }
    
    int shortest(string word1, string word2) {
        int minDist = INT_MAX;
        for (int i = 0, j = 0; i < mp[word1].size() && j < mp[word2].size(); ) {
            minDist = std::min(minDist, std::abs(mp[word1][i] - mp[word2][j]));
            if (mp[word1][i] < mp[word2][j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */