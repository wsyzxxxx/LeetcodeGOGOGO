class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }
        
        int num = numbers[0];
        int freq = 1;
        for (int i = 1; i < numbers.size(); i++) {
           if (freq == 0) {
               num = numbers[i];
               freq = 1;
           } else if (num == numbers[i]) {
               freq++;
           } else {
               freq--;
           }
        }
        
        freq = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (num == numbers[i]) {
                freq++;
            }
        }
        if (freq * 2 <= numbers.size()) {
            num = 0;
        }
        
        return num;
    }
};
