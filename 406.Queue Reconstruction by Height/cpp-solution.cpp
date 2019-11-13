bool cmp(const vector<int> & a, const vector<int>& b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        
        for (vector<vector<int>>::const_iterator it = people.begin(); it != people.end(); it++) {
            vector<vector<int>>::iterator newit = res.begin();
            res.insert(newit + (*it)[1], {(*it)[0], (*it)[1]});
        }
        
        return res;
    }
};
