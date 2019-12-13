class Solution {
private:
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
    int partition(vector<int>& nums, int lo, int hi) {
        int index = hi - 1;
        for (int i = hi - 1; i >= lo; i--) {
            if (nums[i] > nums[hi]) {
                swap(nums, i, index--);
            }
        }
        swap(nums, hi, ++index);
        return index;
    }
    
    void quickSort(vector<int>& nums, int lo, int hi) {
        if (lo < hi) {
            int pivot = partition(nums, lo, hi);
            quickSort(nums, lo, pivot - 1);
            quickSort(nums, pivot + 1, hi);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
