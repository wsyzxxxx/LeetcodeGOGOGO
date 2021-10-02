class Solution {
    public:
        void getResult(vector<vector<int>> &result, vector<int> &row, int n, int start){
            for(int i = start; i <= n/i; ++i){
                if (n % i == 0){
                    row.push_back(i);
                    row.push_back(n/i);
                    result.push_back(row);
                    row.pop_back();
                    getResult(result, row, n/i, i);
                    row.pop_back();
                }
            }
        }
    
        vector<vector<int>> getFactors(int n) {
            vector<vector<int>> result;
            vector<int>row;
            getResult(result, row, n, 2);
            return result;
        }
    };