class Solution {
private:
    std::vector<int> mergeTwoArray(const std::vector<int> & nums1,
                                   const std::vector<int> & nums2,
                                   int k) {
        if (nums1.empty()) {
            return nums2;
        } else if (nums2.empty()) {
            return nums1;
        }
        
        std::vector<int> res(k);
        for (int i = 0, j = 0, index = 0; index < k; ) {
            // if (i == nums1.size() || (j < nums2.size() && nums2[j] > nums1[i])) {
            //     res[index++] = nums2[j++];
            // } else if (j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j])) {
            //     res[index++] = nums1[i++];
            // } else 
            if (compareTwoArray(nums1, nums2, i, j)) {
                res[index++] = nums1[i++];
            } else {
                res[index++] = nums2[j++];
            }
        }
        
        return res;
    }
    std::vector<int> findKElementsFromVector(const std::vector<int> & nums, int k) {
        if (k == 0) {
            return {};
        } else if (k == nums.size()) {
            return nums;
        }
        
        int n = nums.size();
        std::vector<int> res(k);
        for (int i = 0, j = 0; j < n; j++) {
            while (i > 0 && (k-i) < (n-j) && nums[j] > res[i-1]) i--;
            if (i < k) {
                res[i++] = nums[j];
            }
        }
        
        return res;
    }
    bool compareTwoArray(const std::vector<int> & nums1,
                         const std::vector<int> & nums2,
                         int i,
                         int j) {
        if (i == nums1.size()) {
            return false;
        }
        if (j == nums2.size()) {
            return true;
        }
        
        int n = i;
        int m = j;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                return true;
            } else if (nums1[i] < nums2[j]) {
                return false;
            }
            i++;
            j++;
        }
        
//         if (i < nums1.size()) {
//             return nums1[i] > nums1[n];
//         } else if (j < nums2.size()) {
//             return nums2[j] < nums2[m];
//         }
        
        return (i < nums1.size());
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        if (n == 0 && m == 0 || k <= 0) {
            return {};
        }
        if (k == n + m) {
            return mergeTwoArray(nums1, nums2, k);
        }
        
        std::vector<int> res(k, 0);
        for (int i = 0; i <= k; i++) {
            if (i <= n && (k-i) <= m) {
                std::vector<int> v1 = findKElementsFromVector(nums1, i);
                std::vector<int> v2 = findKElementsFromVector(nums2, k-i);
                std::vector<int> v = mergeTwoArray(v1, v2, k);
                
                if (compareTwoArray(v, res, 0, 0)) {
                    res = v;
                }
            }
        }
        
        return res;
    }
};
