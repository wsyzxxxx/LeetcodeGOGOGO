class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) {
            return false;
        }
        
        std::sort(numbers.begin(), numbers.end());
        
        int zeroCount = 0;
        bool first = true;
        for (int i = 0; i < 5; i++) {
            if (numbers[i] == 0) {
                zeroCount++;
            } else {
                if (first) {
                    first = false;
                    continue;
                } else {
                    if (numbers[i] == numbers[i-1]) {
                        return false;
                    } else if (numbers[i] - numbers[i-1] > 1) {
                        if (zeroCount == 0) {
                            return false;
                        }
                        zeroCount--;
                        numbers[i-1]++;
                        i--;
                        continue;
                    }
                }
            }
            //if (zeroCount > 2) {
            //    return false;
            //}
            
        }
        
        return true;
    }
};
