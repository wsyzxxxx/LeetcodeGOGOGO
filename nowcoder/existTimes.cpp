class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty()) {
            return 0;
        }
        
        int index1 = -1;
        int index2 = -1;
        int start = 0;
        int end = data.size();
        
        while (start < end) {
            int mid = (start + end) / 2;
            if (data[mid] == k && (mid == 0 || data[mid-1] != k)) {
                index1 = mid;
                break;
            } else if (data[mid] >= k) {
                end = mid;
            } else if (data[mid] < k) {
                start = mid + 1;
            }
        }
        
        start = 0;
        end = data.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (data[mid] == k && (mid == data.size() || data[mid+1] != k)) {
                index2 = mid;
                break;
            } else if (data[mid] > k) {
                end = mid;
            } else if (data[mid] <= k) {
                start = mid+1;
            }
        }
        
        if (index1 != -1 && index2 != -1) {
            return index2 - index1 + 1;
        } else {
            return 0;
        }
    }
};
