class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return {};
        }
        
        int up = 0;
        int low = n;
        int left = 0;
        int right = n;
        int num = 1;
        std::vector<std::vector<int> > res(n, std::vector<int>(n, 0));
        while (up < low || left < right) {
            if (up < low) {
                for (int i = left; i < right; i++) {
                    res[up][i] = num++;
                }
                up++;
            }
            if (left < right) {
                for (int i = up; i < low; i++) {
                    res[i][right-1] = num++;
                }
                right--;
            }
            if (up < low) {
                for (int i = right-1; i >= left; i--) {
                    res[low-1][i] = num++;
                }
                low--;
            }
            if (left < right) {
                for (int i = low-1; i >= up; i--) {
                    res[i][left] = num++;
                }
                left++;
            }
        }

        return res;
    }
};
