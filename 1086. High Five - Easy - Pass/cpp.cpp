bool cmp(const std::vector<int> & a, const std::vector<int> & b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    } else {
        return a[0] < b[0];
    }
}

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        std::sort(items.begin(), items.end(), cmp);
        
        int size = 0;
        int sum = 0;
        std::vector<std::vector<int> > res;
        for (int i = 0; i < items.size(); i++) {
            if (size == 5) {
                while (i < items.size() && items[i-1][0] == items[i][0]) {
                    i++;
                }
                i--;
                res.push_back({items[i][0], sum/5});
                sum = 0;
                size = 0;
            } else {
                sum += items[i][1];
                //std::cout << sum << std::endl;
                size++;
            }
        }
        if (size == 5) {
            res.push_back({items.back()[0], sum/5});
        }
        
        return res;
    }
};
