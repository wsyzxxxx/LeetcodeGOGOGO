class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        std::vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        
        int leftBoarder = 0;
        int rightBoarder = matrix[0].size();
        int upBoarder = 0;
        int downBoarder = matrix.size();
        
        while (leftBoarder < rightBoarder ||
               upBoarder < downBoarder) {
            if (upBoarder < downBoarder) {
                for (int i = leftBoarder; i < rightBoarder; i++) {
                    res.push_back(matrix[upBoarder][i]);
                }
                upBoarder++;
            }
            if (leftBoarder < rightBoarder) {
                for (int i = upBoarder; i < downBoarder; i++) {
                    res.push_back(matrix[i][rightBoarder-1]);
                }
                rightBoarder--;
            }
            if (upBoarder < downBoarder) {
                for (int i = rightBoarder-1; i >= leftBoarder; i--) {
                    res.push_back(matrix[downBoarder-1][i]);
                }
                downBoarder--;
            }
            if (leftBoarder < rightBoarder) {
                for (int i = downBoarder-1; i >= upBoarder; i--) {
                    res.push_back(matrix[i][leftBoarder]);
                }
                leftBoarder++;
            }
        }
        
        return res;
    }
};
