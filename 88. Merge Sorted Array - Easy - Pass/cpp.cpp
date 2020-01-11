class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.size() < m+n || nums2.size() < n || n == 0) {
            return;
        }
        
        int i = m - 1;
        int j = n - 1;
        int currIndex = m + n - 1;
        while (currIndex >= 0) {
            if (i < 0) {
                nums1[currIndex--] = nums2[j--];
            } else if (j < 0) {
                return;
            } else {
                nums1[currIndex--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
            }
        }
        
        return;
    }
};
