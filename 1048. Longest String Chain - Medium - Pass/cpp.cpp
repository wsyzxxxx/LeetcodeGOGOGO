int dp[1005];

class Solution {
private:
    bool isPrece(const std::string & a, const std::string & b) {
        bool oneDiff = false;
        for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
            if (a[i] != b[j]) {
                if (!oneDiff) {
                    i--;
                    oneDiff = true;
                } else {
                    //std::cout << "not" << a << " " << b << std::endl;
                    return false;
                }
            }
        }
        //std::cout << "not" << a << " " << b << std::endl;
        return a.size() == b.size() - 1;
    }
public:
    int longestStrChain(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            dp[i] = 1;
        }
        
        std::sort(words.begin(), words.end(), [](const std::string & a, const std::string & b) {
            return a.size() > b.size();
        });
        
        int last = 0;
        int maxSize = 1;
        for (int i = 1; i < words.size(); i++) {
            while (words[last].size() > words[i].size() + 1) {
                last++;
            }
            std::cout << words[i] <<std::endl;
            for (int j = last; words[j].size() > words[i].size(); j++) {
                //std::cout << words[i] << " " << words[j] << std::endl;
                if (isPrece(words[i], words[j])) {
                    //std::cout << words[i] << " " << words[j] << std::endl;
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            
            maxSize = std::max(maxSize, dp[i]);
        }
        
        return maxSize;
    }
};