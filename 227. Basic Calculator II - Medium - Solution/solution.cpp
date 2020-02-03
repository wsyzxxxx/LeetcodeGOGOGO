class Solution {
private:
    void jumpSpaces(std::string & s, int & i) {
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
    }
public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }
        
        int i = 0;
        int ans = 0;
        int inner_ans = 0;
        char op = '+';
        jumpSpaces(s, i);
        while (i < s.size()) {
            //std::cout << inner_ans << std::endl;
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i++] - '0');
                }
                //std::cout << inner_ans << " " << op << " " << num << std::endl;
                switch (op) {
                    case '+':
                        inner_ans += num;
                        break;
                    case '-':
                        inner_ans -= num;
                        break;
                    case '*':
                        inner_ans *= num;
                        break;
                    case '/':
                        inner_ans /= num;
                        break;
                }
            } else {
                op = s[i++];
                if (op == '+' || op == '-') {
                    //std::cout << op << std::endl;
                    ans += inner_ans;
                    inner_ans = 0;
                }
            }
            jumpSpaces(s, i);
        }
        
        return ans + inner_ans;
    }
};
