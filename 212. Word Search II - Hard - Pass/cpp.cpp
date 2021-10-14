bool visited[15][15];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

class Solution {
private:
    struct TrieNode {
        bool isFinal;
        TrieNode * children[26];
        TrieNode() {
            this->isFinal = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode * root;
    std::unordered_set<std::string> result;
    
    void addString(const std::string & word) {
        TrieNode * curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) {
                curr->children[word[i]-'a'] = new TrieNode();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->isFinal = true;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode * curr, std::string & currWord) {
        if (curr->isFinal) {
            result.insert(currWord);
        }
        
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[nx].size() || visited[nx][ny]) {
                continue;
            }
            
            if (curr->children[board[nx][ny]-'a'] == nullptr) {
                continue;
            }
            
            visited[nx][ny] = true;
            currWord.push_back(board[nx][ny]);
            dfs(board, nx, ny, curr->children[board[nx][ny]-'a'], currWord);
            currWord.pop_back();
            visited[nx][ny] = false;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        
        for (auto & word : words) {
            addString(word);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (root->children[board[i][j]-'a'] != nullptr) {
                    std::memset(visited, false, sizeof(visited));
                    std::string curr(1, board[i][j]);
                    visited[i][j] = true;
                    dfs(board, i, j, root->children[board[i][j]-'a'], curr);
                }
            }
        }
        
        return std::vector<std::string>(result.begin(), result.end());
    }
};