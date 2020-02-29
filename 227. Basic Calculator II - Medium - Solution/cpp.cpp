class Solution {
private:
    std::deque<char> ops;
    std::deque<int> nums;
    int cal(int num1, int num2, char op) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                return 0;
        }
    }
public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }
        
        while (!ops.empty()) {
            ops.pop_back();
        }
        while (!nums.empty()) {
            nums.pop_back();
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] >= '0' && s[i] <='9') {
                long num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <='9') {
                    num = num * 10 + s[i++] - '0';
                }
                while (!ops.empty() && (ops.back() == '*' || ops.back() == '/')) {
                    num = cal(nums.back(), num, ops.back());
                    nums.pop_back();
                    ops.pop_back();
                }
                nums.push_back(num);
                i--;
            } else {
                ops.push_back(s[i]);
            }
        }
        
        while (!ops.empty()) {
            int num1 = nums.front();
            nums.pop_front();
            int num2 = nums.front();
            nums.pop_front();
            num1 = cal(num1, num2, ops.front());
            ops.pop_front();
            nums.push_front(num1);
        }
        
        return nums.front();
    }
};
