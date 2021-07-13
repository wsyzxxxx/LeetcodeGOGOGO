class Solution {
private:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = rand() % (end - start + 1) + start;
        
        std::swap(nums[pivot], nums[end]);
        
        int left = start - 1;
        for (int i = start; i < end; i++) {
            if (nums[i] <= nums[end]) {
                std::swap(nums[i], nums[++left]);
            }
        }
        
        std::swap(nums[end], nums[++left]);
        
        return left;
    }
    int findKth(vector<int>& nums, int start, int end, int k) {
        int index = partition(nums, start, end);
        
        if (index == k) {
            return nums[k];
        } else if (index < k) {
            return findKth(nums, index+1, end, k);
        } else {
            return findKth(nums, start, index-1, k);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size()-1, nums.size()-k);
    }
};