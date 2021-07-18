/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);
        
        int minCol = -1;
        for (int i = 0; i < rows; i++) {
            int start = 0;
            int end = cols-1;
            
            while (start < end) {
                int mid = (start + end) / 2;
                if (binaryMatrix.get(i, mid) == 1) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            }
            
            int num = binaryMatrix.get(i, start);
            if (num == 0) {
                continue;
            }
            minCol = minCol == -1 ? start : Math.min(minCol, start);
        }
        
        return minCol;
    }
}