class Solution {
private:
    int res;
    void findAllAnswers(int n, int curr, int lb, int rb, int cb) {
        if (curr == n) {
            res++;
            return;
        }
        
        int canNotPlace = lb | rb | cb;
        
        for (int i = 0; i < n; i++) {
            if ((canNotPlace >> i) & 1) {
                continue;
            }
            findAllAnswers(n, curr+1, (lb | (1 << i)) << 1, (rb | (1 << i)) >> 1, cb | (1 << i));
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
        //std::vector<int> visited(n, -1);
        findAllAnswers(n, 0, 0, 0, 0);
        
        return res;
    }
};
