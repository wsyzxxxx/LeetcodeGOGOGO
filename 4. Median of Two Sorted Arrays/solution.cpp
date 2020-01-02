class Solution {
public:
    int helper(vector<int> & nums1, vector<int> & nums2, 
               int l, int r, int target) {
        if (nums1.size()-l > nums2.size()-r) {
            return helper(nums2, nums1, r, l, target);
        }
        if (nums1.size()-l == 0) {
            return nums2[r+target-1];
        }
        if (target == 1) {
            return std::min(nums1[l], nums2[r]);
        }
        
        int i = std::min((int)nums1.size()-l, target/2);
        int j = std::min((int)nums2.size()-r, target/2);
        if (nums1[l+i-1] > nums2[r+j-1]) {
            return helper(nums1, nums2, l, r+j, target-j);
        } else {
            return helper(nums1, nums2, l+i, r, target-i);
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int lo = helper(nums1, nums2, 0, 0, (m + n + 1)/2);  
        int hi = helper(nums1, nums2, 0, 0, (m + n + 2)/2);
        return (lo + hi)/2.0;
    }
    
};
