class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }
        
        int left = 0;
        int right = height.size() - 1;
        int maxV = (height.size()-1) * std::min(height[0], height[height.size()-1]);
        while (left < right) {
            if (height[left] < height[right]) {
                int newLeft = left+1;
                while (newLeft < right && height[newLeft] <= height[left]) {
                    newLeft++;
                }
                if (newLeft < right) {
                    int newV = (right - newLeft) * std::min(height[newLeft], height[right]);
                    maxV = std::max(maxV, newV);
                }
                left = newLeft;
            } else {
                int newRight = right-1;
                while (newRight > left && height[newRight] <= height[right]) {
                    newRight--;
                }
                if (newRight > left) {
                    int newV = (newRight - left) * std::min(height[left], height[newRight]);
                    maxV = std::max(maxV, newV);
                }
                right = newRight;
            }
        }
        
        return maxV;
    }
};
