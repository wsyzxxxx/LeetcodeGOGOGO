class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> res;
        if (digits.empty()) {
            return res;
        }
        
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] + carry == 10) {
                res.push_back(0);
                carry = 1;
            } else {
                res.push_back(digits[i]+carry);
                carry = 0;
            }
        }
        if (carry) {
            res.push_back(1);
        }
        
        for (int i = 0; i < res.size()/2; i++) {
            std::swap(res[i], res[res.size()-1-i]);
        }
        
        return res;
    }
};
