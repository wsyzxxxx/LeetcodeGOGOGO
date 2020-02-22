class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            return 0;
        }
        
        int count = 0;
        int last = 0;
        int minInRange = std::numeric_limits<int>::max();
        int maxInRange = std::numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            minInRange = std::min(minInRange, arr[i]);
            maxInRange = std::max(maxInRange, arr[i]);
            
            if (minInRange == last && maxInRange == i) {
                count++;
                minInRange = std::numeric_limits<int>::max();
                maxInRange = std::numeric_limits<int>::min();
                last = i + 1;
            }
        }
        
        return count;
    }
};
