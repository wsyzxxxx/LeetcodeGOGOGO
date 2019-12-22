class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        std::vector<int> res;
        if (array.empty()) {
            return res;
        }
        
        int start = 0;
        int end = array.size() - 1;
        while (start < end) {
            if (array[start] + array[end] == sum) {
                if (res.empty()) {
                    res.push_back(array[start]);
                    res.push_back(array[end]);
                } else if (array[start] * array[end] < res[0] * res[1]) {
                        res.clear();
                        res.push_back(array[start]);
                        res.push_back(array[end]);
                }
                start++;
                end--;
            } else if (array[start] + array[end] < sum) {
                start++;
            } else {
                end--;
            }
        }
        
        return res;
                        
    }
};
