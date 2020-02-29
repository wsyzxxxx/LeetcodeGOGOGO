class Solution {
private:
    int res;
    // void converToString (std::vector<int> & visited) {
    //     std::vector<std::string> ans;
    //     for (int i = 0; i < visited.size(); i++) {
    //         std::string curr = "";
    //         for (int j = 0; j < visited.size(); j++) {
    //             if (j == visited[i]) {
    //                 curr.push_back('Q');
    //             } else {
    //                 curr.push_back('.');
    //             }
    //         }
    //         ans.push_back(curr);
    //     }
    //     res.push_back(ans);
    // }
    void findAllAnswers(std::vector<int> & visited, int n, int curr) {
        if (curr == n) {
            res++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                bool canBePlaced = true;
                for (int j = 0; j < n; j++) {
                    if (visited[j] == -1) {
                        continue;
                    }
                    
                    if (i - j == curr - visited[j] ||
                        i - j == visited[j] - curr) {
                        canBePlaced = false;
                        break;
                    }
                }
                if (canBePlaced) {
                    visited[i] = curr;
                    findAllAnswers(visited, n, curr+1);
                    visited[i] = -1;
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        res = 0;
        std::vector<int> visited(n, -1);
        findAllAnswers(visited, n, 0);
        
        return res;
    }
};
