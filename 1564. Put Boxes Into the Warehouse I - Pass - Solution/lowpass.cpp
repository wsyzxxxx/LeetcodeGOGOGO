class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        std::sort(boxes.begin(), boxes.end());
        
        std::stack<int> s;
        for (int i = 0; i < warehouse.size(); i++) {
            if (s.empty() || warehouse[i] < warehouse[s.top()]) {
                s.push(i);
            }
        }
        
        int count = 0;
        for (int i = warehouse.size()-1, j = 0; j < boxes.size() && i >= 0; j++) {
            if (i < s.top()) {
                s.pop();
            }
            if (boxes[j] <= warehouse[s.top()]) {
                i--;
                count++;
            } else {
                i = s.top() - 1;
                j--;
            }
        }
        
        return count;
    }
};