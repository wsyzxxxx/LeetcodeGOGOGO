class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        if (n == 0 || k >= num.size()) {
            return "0";
        }
        
        std::stack<char> s;
        for (const auto i : num) {
            while (!s.empty() && k > 0 && s.top() > i) {
                s.pop();
                k--;
            }
            s.push(i);
        }
        
        std::string res;
        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        while (!res.empty() && res[0] == '0') {
            res.erase(res.begin());
        }
        
        while (!res.empty() && k > 0) {
            res.pop_back();
            k--;
        }
        
        if (res.empty()) {
            res = "0";
        }
        return res;
    }
};
