class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        
        std::vector<int> left(heights.size(), 0);
        std::vector<int> right(heights.size(), 0);
        
        for (int i = 0; i < heights.size(); i++) {
            int l = i-1;
            while (l >= 0 && heights[l] >= heights[i]) {
                l = left[l];
            }
            left[i] = l;
        }
        
        for (int i = heights.size()-1; i >= 0; i--) {
            int r = i+1;
            while (r < heights.size() && heights[r] >= heights[i]) {
                r = right[r];
            }
            right[i] = r;
        }
        
        int maxH = heights[0];
        for (int i = 0; i < heights.size(); i++) {
            maxH = std::max(maxH, (right[i] - left[i] - 1) * heights[i]);
        }
        
        return maxH;
    }
};
