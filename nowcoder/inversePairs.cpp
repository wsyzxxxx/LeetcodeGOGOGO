class Solution {
private:
    int divideAndCount(std::vector<int> & data,
                       std::vector<int> & copy,
                       int start,
                       int end) {
        if (start == end) {
            copy[start] = data[start];
            return 0;
        }
        
        int mid = (start + end) / 2;
        int count1 = divideAndCount(copy, data, start, mid);
        int count2 = divideAndCount(copy, data, mid+1, end);
        
        int count = 0;
        int index1 = mid;
        int index2 = end;
        while (index1 >= start && index2 > mid) {
            if (data[index1] > data[index2]) {
                count += index2 - mid;
                count %= 1000000007;
                copy[end--] = data[index1--];
            } else {
                copy[end--] = data[index2--];
            }
        }
        
        for (; index1 >= start; index1--) {
            copy[end--] = data[index1];
        }
        for (; index2 > mid; index2--) {
            copy[end--] = data[index2];
        }
        
        return (count + count1 + count2) % 1000000007;
    }
public:
    int InversePairs(vector<int> & data) {
        std::vector<int> nums(data.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = data[i];
        }
        return divideAndCount(data, nums, 0, data.size()-1);
    }
};
