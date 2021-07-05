class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = ratings.size();
        if (ratings.size() < 2) {
            return count;
        }
        
        int level = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                level++;
                count += level;
            } else if (ratings[i] == ratings[i-1]) {
                level = 0;
            } else {
                int tempLevel = 0;
                while (i < ratings.size() && ratings[i] < ratings[i-1]) {
                    tempLevel++;
                    i++;
                }
                if (tempLevel >= level) {
                    count -= level;
                    count += tempLevel * (tempLevel + 1) / 2;
                } else {
                    count += tempLevel * (tempLevel - 1) / 2;
                }
                i--;
                level = 0;
            }
        }
        
        return count;
    }
};