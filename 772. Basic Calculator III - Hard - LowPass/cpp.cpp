class Solution {
private:
    std::stack<char> ops;
    std::stack<char> ops2;
    std::stack<long long> cal;
    std::stack<long long> cal2;
    
    void calculate(std::stack<long long> & cal, std::stack<char> & ops, int order) {
        long long num1, num2;
        if (order) {
            num2 = cal.top();
            cal.pop();
            num1 = cal.top();
            cal.pop();
        } else {
            num1 = cal.top();
            cal.pop();
            num2 = cal.top();
            cal.pop();
        }
        //std::cout << num1 << " " << num2 << " " << (char)ops.top() << std::endl;
        switch (ops.top()) {
            case '+':
                cal.push(num1 + num2);
                break;
            case '-':
                cal.push(num1 - num2);
                break;
            case '*':
                cal.push(num1 * num2);
                break;
            case '/':
                cal.push(num1 / num2);
                break;
            default:
                return;
        }
        ops.pop();
    }
public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size();
        while (!ops.empty()) {
            ops.pop();
        }
        while (!cal.empty()) {
            cal.pop();
        }

        bool neg = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                long long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i++] - '0';
                }
                i--;
                if (neg) {
                    cal.push(-num);
                    neg = false;
                } else {
                    cal.push(num);
                }
                while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                    calculate(cal, ops, true);
                }
            } else if (s[i] == '(') {
                ops.push(s[i]);
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    ops2.push(ops.top()); ops.pop();
                    cal2.push(cal.top()); cal.pop();
                }
                cal2.push(cal.top()); cal.pop();
                while (!ops2.empty()) {
                    calculate(cal2, ops2, false);
                }
                cal.push(cal2.top()); cal2.pop();    
                ops.pop();
                while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                    calculate(cal, ops, true);
                }
            } else {
                if (s[i] == '-') {
                    int j = i-1;
                    while (j >= 0 && s[j] == ' ') j--;
                    if (cal.empty() || s[j] == '(') {
                        neg = true;
                    } else {
                        ops.push(s[i]);
                    }
                } else {
                    ops.push(s[i]);
                }
            }
        }
        while (!ops.empty()) {
            ops2.push(ops.top()); ops.pop();
            cal2.push(cal.top()); cal.pop();
        }
        cal2.push(cal.top()); cal.pop();
        while (!ops2.empty()) {
            calculate(cal2, ops2, false);
        }
        cal.push(cal2.top()); cal2.pop(); 
        
        return cal.top();
    }
};
