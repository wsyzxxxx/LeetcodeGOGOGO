class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        
        std::vector<int> leftMax(height.size()), rightMax(height.size());
        int n = height.size();
        leftMax[0] = height[0];
        for (int i = 1; i < leftMax.size(); i++) {
            leftMax[i] = std::max(leftMax[i-1], height[i]);
        }
        
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = std::max(rightMax[i+1], height[i]);
        }
        
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            sum += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return sum;
    }
};
