class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty()) {
            return;
        }
        
        int start = 0;
        int end = array.size()-1;
        
        while (start < end) {
            while (start < end && (array[start] & 1) == 1) {
                start++;
            }
            while (start < end && (array[end] & 1) == 0) {
                end--;
            }
            
            if (start < end) {
                swap(array[start], array[end]);
            }
        }
        
        sort(array.begin(), array.begin()+start);
        sort(array.begin()+start, array.end());
    }
};
