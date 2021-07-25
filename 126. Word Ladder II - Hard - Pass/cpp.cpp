bool canBeNext[1005][1005];
int visited[1005];

class Solution {
private:
    std::vector<std::vector<std::string>> result;
    int n;
    int minLen;
    bool checkNext(const std::string & a, const std::string & b) {
        if (a.size() != b.size()) {
            return false;
        }
        
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            diff += a[i] == b[i] ? 0 : 1;
            
            if (diff > 1) {
                return false;
            }
        }
        
        return diff == 1;
    }
    void bfs(const std::string & startWord,
             const std::string & endWord,
             std::vector<std::string>& wordList) {
        
        std::queue<std::pair<int, std::vector<std::string>>> q;
        for (int i = 0; i < wordList.size(); i++) {
            if (checkNext(startWord, wordList[i])) {
                visited[i] = 1;
                q.push({i, {startWord, wordList[i]}});
            }
        }
        
        while (!q.empty()) {
            int index = q.front().first;
            std::vector<std::string> paths = q.front().second;
            q.pop();
            
            if (!result.empty() && paths.size() > result[0].size()) {
                break;
            }
            if (paths.back() == endWord) {
                result.push_back(paths);
                continue;
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (canBeNext[index][i] && (visited[i] == 0 || visited[i] >= visited[index]+1)) {
                    std::vector<std::string> newPath = paths;
                    newPath.push_back(wordList[i]);
                    visited[i] = visited[index]+1;
                    q.push({i, newPath});
                }
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        std::memset(canBeNext, false, sizeof(canBeNext));
        std::memset(visited, 0, sizeof(visited));
        result.clear();
        
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (checkNext(wordList[i], wordList[j])) {
                    canBeNext[i][j] = canBeNext[j][i] = true;
                }
            }
        }
        
        bfs(beginWord, endWord, wordList);
        
        return result;
    }
};
