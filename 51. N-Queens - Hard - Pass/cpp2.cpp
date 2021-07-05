std::unordered_map<int, std::vector<std::vector<int>>> mp;

class Solution {
private:
    std::vector<std::vector<std::string>> toGraph(const std::vector<std::vector<int>> & rows) {
        if (rows.empty()) {
            return {};
        }
        
        std::vector<std::vector<std::string>> result(rows.size(), std::vector<std::string>(rows[0].size()));
        for (int i = 0; i < rows.size(); i++){
            for (int j = 0; j < rows[i].size(); j++) {
                for (int k = 0; k < rows[i].size(); k++) {
                    result[i][j] += k == rows[i][j] ? 'Q' : '.';
                }
            }
        }
        
        return result;
    }
    bool checkAvail(std::vector<int> & curr, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (row - i == col - curr[i] || row - i == curr[i] - col) {
                return false;
            }
        }
        
        return true;
    }
    void findSolution(std::vector<std::vector<int>> & result, std::vector<int> & curr, int row, int n,
                      std::vector<bool> & visited) {
        if (row == n) {
            result.push_back(curr);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && checkAvail(curr, row, i)) {
                visited[i] = true;
                curr[row] = i;
                findSolution(result, curr, row+1, n, visited);
                visited[i] = false;
            }
        }
    }
    std::vector<std::vector<int>> findSolutions(int n) {
        std::vector<std::vector<int>> result;
        std::vector<bool> visited(n, false);
        std::vector<int> curr(n, 0);
        
        for (int i = 0; i < n; i++) {
            visited[i] = true;
            curr[0] = i;
            findSolution(result, curr, 1, n, visited);
            visited[i] = false;
        }
        
        return result;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (mp.find(n) != mp.end()) {
            return toGraph(mp[n]);
        }
        
        mp[n] = findSolutions(n);
        return toGraph(mp[n]);
    }
};