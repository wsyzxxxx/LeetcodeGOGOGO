class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        std::vector<std::vector<std::pair<int, int>>> pointers(26);
        for (int i = 0; i < words.size(); i++) {
            pointers[words[i][0] - 'a'].push_back({i, 0});
        }
        
        int ans = 0;
        for (const auto ch : s) {
            std::vector<std::pair<int, int>> newPointer;
            
            for (const auto & kv : pointers[ch - 'a']) {
                if (kv.second+1 == words[kv.first].size()) {
                    ans++;
                } else {
                    if (words[kv.first][kv.second+1] == ch) {
                        newPointer.push_back({kv.first, kv.second+1});
                    } else {
                        pointers[words[kv.first][kv.second+1] - 'a'].push_back({kv.first, kv.second+1});
                    }
                }
            }
            
            pointers[ch - 'a'] = newPointer;
        }
        
        return ans;
    }
};