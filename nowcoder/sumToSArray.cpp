class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        std::vector<std::vector<int> > res;
        if (sum < 3) {
            return res;
        }
        
        int start = 1;
        int end = 2;
        int currSum = 3;
        
        while (start < end) {
            if (currSum == sum) {
                std::vector<int> newItem;
                for (int i = start; i <= end; i++) {
                    newItem.push_back(i);
                }
                res.push_back(newItem);
            } else if (currSum > sum) {
                while (currSum > sum && start < end) {
                    currSum -= start;
                    start++;
                }
                continue;
            }
            
            end++;
            currSum += end;
        }
        
        return res;
    }
};
