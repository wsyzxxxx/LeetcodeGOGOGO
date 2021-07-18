/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
private:
    int searchFirstOne(BinaryMatrix &binaryMatrix, int row, int m) {
        int start = 0;
        int end = m;
        
        while (start < end) {
            int mid = (start + end) / 2;
            if (binaryMatrix.get(row, mid) == 0) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return start;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        std::vector<int> dim = binaryMatrix.dimensions();

        int n = dim[0];
        int m = dim[1];
        
        if (n == 0 || m == 0) {
            return -1;
        }
        
        int minIndex = m;
        for (int i = 0; i < n; i++) {
            minIndex = std::min(minIndex, searchFirstOne(binaryMatrix, i, m));
        }
        
        return minIndex == m ? -1 : minIndex;
    }
};