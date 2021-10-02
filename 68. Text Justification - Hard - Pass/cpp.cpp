class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::string> result;
        int index = 0;
        
        while (index < words.size()) {
            int currSize = 0;
            int currCount = 0;
            int realSize = 0;
            while (index < words.size() && currSize + words[index].size() <= maxWidth) {
                currSize += words[index].size() + 1;
                realSize += words[index].size();
                currCount++;
                index++;
            }
            currSize--;
            
            if (index == words.size() || currCount == 1) {
                std::string str;
                for (int i = index-currCount; i < index-1; i++) {
                    str += words[i] + ' ';
                }
                str += words[index-1];
                while (str.size() < maxWidth) {
                    str += ' ';
                }
                result.push_back(str);
            } else {
                int extra = (maxWidth - realSize) % (currCount - 1);
                int oneEmpty = (maxWidth - realSize) / (currCount - 1);
                std::string str;
                for (int i = index-currCount; i < index-1; i++) {
                    str += words[i];
                    for (int j = 0; j < oneEmpty; j++) {
                        str += ' ';
                    }
                    if (extra > 0) {
                        str += ' ';
                        extra--;
                    }
                }
                
                str += words[index-1];
                result.push_back(str);
            }
        }
        return result;
    }
};