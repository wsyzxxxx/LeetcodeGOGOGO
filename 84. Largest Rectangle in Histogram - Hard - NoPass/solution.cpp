class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        
        std::stack<int> s;
        int maxH = heights[0];
        s.push(0);
        heights.push_back(0);
        for (int i = 1; i < heights.size(); i++) {            
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int index = s.top();
                s.pop();
                
                int left = s.empty() ? -1 : s.top();
                maxH = std::max(maxH, heights[index] * (i - left - 1));
            }
            
            s.push(i);
        }
        
        return maxH;
    }
};
