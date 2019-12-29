bool isValid = true;

class Solution {
private:
    int Partition(std::vector<int> & nums, int start, int end) {
        int ranIndex = rand() % (end - start + 1) + start;
        std::swap(nums[ranIndex], nums[end]);
        
        int small = start - 1;
        for (int i = start; i < end; i++) {
            if (nums[i] < nums[end]) {
                ++small;
                if (i != small) {
                    std::swap(nums[small], nums[i]);
                }
            }
        }
        
        ++small;
        std::swap(nums[small], nums[end]);
        
        return small;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) {
            isValid = false;
            return 0;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        int index = -1;
        while (index != nums.size() - k) {
            index = Partition(nums, start, end);
            if (index < nums.size() - k) {
                start = index + 1;
            } else {
                end = index - 1;
            }
        }
        
        return nums[index];
    }
};
