class SparseVector {
private:
    std::unordered_map<int, int> mp;
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                mp[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        
        for (const auto & kv : mp) {
            if (vec.mp.find(kv.first) != vec.mp.end()) {
                product += kv.second * vec.mp[kv.first];
            }
        }
        
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);