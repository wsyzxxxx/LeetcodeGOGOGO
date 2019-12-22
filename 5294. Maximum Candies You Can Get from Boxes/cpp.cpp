class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,                                     vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        if (initialBoxes.empty()) {
            return 0;
        }

        std::vector<bool> hasBoxes(status.size(), false);
        for (int i = 0; i < initialBoxes.size(); i++) {
            hasBoxes[initialBoxes[i]] = true;
        }

        int count = 0;
        bool changed = true;
        while (changed) {
            changed = false;

            for (int i = 0; i < hasBoxes.size(); i++) {
                if (status[i] != 0 && hasBoxes[i] == true) {
                    hasBoxes[i] = false;
                    changed = true;
                    for (int j = 0; j < keys[i].size(); j++) {
                        status[keys[i][j]] = 1;
                    }
                    for (int j = 0; j < containedBoxes[i].size(); j++) {
                        hasBoxes[containedBoxes[i][j]] = true;
                    }
                    count += candies[i];
                }
            }   
        }

        return count;
    }
};
