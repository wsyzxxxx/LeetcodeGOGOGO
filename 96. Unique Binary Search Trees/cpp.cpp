class Solution {
private:
    int num[10000];
    int calculateSubTree(int start, int end) {
        if (end <= start) {
            return 1;
        }
        if (num[end-start] != -1) {
            return num[end-start];
        }
        int count = 0;
        for (int i = start; i <= end; i++) {
            int leftCount = calculateSubTree(start, i-1);
            int rightCount = calculateSubTree(i+1, end);
            count += leftCount * rightCount;
        }
        num[end-start] = count;
        return count;
    }
public:
    int numTrees(int n) {
        if (n <= 0) {
            return -1;
        }
        for (int i = 0; i < 10000; i++) {
            num[i] = -1;
        }
        
        return calculateSubTree(1, n);
    }
};
