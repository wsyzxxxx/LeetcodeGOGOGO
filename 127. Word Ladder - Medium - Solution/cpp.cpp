class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty() || beginWord.size() != endWord.size()) {
            return 0;
        }
        
        std::unordered_map<std::string, int> mp;
        for (const auto word : wordList) {
            mp[word] = -1;
        }
        mp[beginWord] = 1;
        std::queue<std::string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            std::string word = q.front();
            q.pop();
            
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                std::string currWord = word;
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    if (mp.find(word) != mp.end() && mp[word] == -1) {
                        if (word == endWord) {
                            return mp[currWord] + 1;
                        }
                        q.push(word);
                        mp[word] = mp[currWord] + 1;
                    }
                }
                word[i] = ch;
            }
        }
        
        return 0;
    }
};
