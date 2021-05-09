class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        std::sort(boxes.begin(), boxes.end(), [](int a, int b) {return a > b;});
        
        int count = 0;
        for (int i = 0, j = 0; i < warehouse.size() && j < boxes.size();) {
            while (j < boxes.size() && boxes[j] > warehouse[i]) {
                j++;
            }
            
            if (j < boxes.size()) {
                j++;
                i++;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};