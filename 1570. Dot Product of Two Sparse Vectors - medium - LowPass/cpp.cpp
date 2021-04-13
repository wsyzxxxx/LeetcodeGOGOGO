class SparseVector {
private:
    std::vector<int> nums1;
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                nums1.push_back(nums[i]);
            } else {
                int count = 0;
                while (i < nums.size() && nums[i] == 0) {
                    count++;
                    i++;
                }
                i--;
                nums1.push_back(-count);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        for (int i = 0, j = 0; i < nums1.size() && j < vec.nums1.size(); ) {
            if (nums1[i] > 0 && vec.nums1[j] > 0) {
                //std::cout << i  << " " << j << std::endl;
                product += nums1[i++] * vec.nums1[j++];
            } else if (nums1[i] < 0) {
                while (i < nums1.size() && nums1[i] < 0) {
                    if (vec.nums1[j] > 0) {
                        j++;
                        nums1[i]++;
                    } else if (nums1[i] < vec.nums1[j]) {
                        nums1[i] -= vec.nums1[j++];
                    } else {
                        vec.nums1[j] -= nums1[i++];
                    }
                }
                if (i < nums1.size() && nums1[i] == 0) {
                    i++;
                }
            } else {
                while (j < vec.nums1.size() && vec.nums1[j] < 0) {
                    if (nums1[i] > 0) {
                        i++;
                        vec.nums1[j]++;
                    } else if (nums1[i] < vec.nums1[j]) {
                        nums1[i] -= vec.nums1[j++];
                    } else {
                        vec.nums1[j] -= nums1[i++];
                    }
                }
                if (j < vec.nums1.size() && vec.nums1[j] == 0) {
                    j++;
                }
            }
        }
        
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);