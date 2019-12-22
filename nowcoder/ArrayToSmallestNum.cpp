class Compare {
public:
    bool operator()(const std::string & lhs,
                    const std::string & rhs) {
        std::string first = lhs + rhs;
        std::string second = rhs + lhs;
        
        return first < second;
    }
};

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        std::string res = "";
        if (numbers.empty()) {
            return res;
        }
        
        std::vector<std::string> strList;
        
        for (int i = 0; i < numbers.size(); i++) {
            std::ostringstream oss;
            oss << numbers[i];
            strList.push_back(oss.str());
        }
        
        std::sort(strList.begin(), strList.end(), Compare());
        
        for (int i = 0; i < strList.size(); i++) {
            res += strList[i];
        }
        
        return res;
    }
};
