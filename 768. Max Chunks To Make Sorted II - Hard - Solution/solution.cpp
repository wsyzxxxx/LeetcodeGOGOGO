class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            return 0;
        }
        
        std::vector<int> leftMax(n);
        std::vector<int> rightMin(n);
        
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = std::max(leftMax[i-1], arr[i]);
        }
        
        rightMin[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMin[i] = std::min(rightMin[i+1], arr[i]);
        }
        
        int count = 1;
        for (int i = 0; i < n-1; i++) {
            if (leftMax[i] <= rightMin[i+1]) {
                count++;
            }
            //std::cout << leftMax[i] << " " << rightMin[i] << std::endl;
        }
        //count = std::min(n, count);
        
        return count;
    }
};
