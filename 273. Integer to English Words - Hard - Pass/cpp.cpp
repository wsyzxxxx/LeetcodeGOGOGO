class Solution {
private:
    const std::string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    const std::string twoDigits[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    const std::string quantity[3] = {"Thousand", "Million", "Billion"};
    std::string convertNum(int curr) {
        //std::cout << curr << std::endl;
        if (curr < 20) {
            return digits[curr];
        }
        
        std::string res = "";
        int hundreds = curr / 100;
        if (hundreds) {
            res += digits[hundreds];
            res += " Hundred";
        }
        int rest = curr % 100;
        if (rest && !res.empty()) {
            res += " ";
        }
        if (rest > 0 && rest < 20) {
            res += digits[rest];
            return res;
        } else if (rest > 0) {
            res += twoDigits[rest / 10];
        }
        if (rest % 10 && !res.empty()) {
            res += " ";
        }
        if (rest % 10) {
            res += digits[rest % 10];
        }
        return res;
    }
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        
        std::string res = "";
        int quant = 1000000000;
        int count = 2;
        while (num > 0 && quant > 0) {
            std::string curr = "";

            if (num / quant > 0) {
                curr = convertNum(num / quant);
                if (!res.empty()) {
                    res += " " + curr;
                } else {
                    res = curr;
                }
            }
            if (!curr.empty() && count >= 0) {
                res += " " + quantity[count];
            }
            num = num % quant;
            quant /= 1000;
            count--;
        }
        
        return res;
    }
};
