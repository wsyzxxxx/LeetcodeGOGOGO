class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int> > res;
        if (numRows == 0) {
            return res;
        }
        res.push_back({1});
        for (int i = 2; i <= numRows; i++) {
            std::vector<int> newRow;
            newRow.push_back(1);
            for (int j = 1; j < res[i-2].size(); j++) {
                newRow.push_back(res[i-2][j-1] + res[i-2][j]);
            }
            newRow.push_back(1);
            res.push_back(newRow);
        }
        
        return res;
    }
};
