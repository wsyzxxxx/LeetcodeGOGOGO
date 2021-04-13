class Solution {
private:
    bool compare(int a, int b, int x) {
        int aba = std::abs(a - x);
        int abb = std::abs(b - x);
        
        return aba == abb ? a < b : aba < abb;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size()) {
            return arr;
        }
        
        std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), x);
        std::vector<int>::iterator left = (it == arr.end() || it != arr.begin() && compare(*(it-1), *it, x)) ? it-1 : it;
        std::vector<int>::iterator right = left;
        
        while (--k) {
            if (left != arr.begin() && right+1 != arr.end() && compare(*(left-1), *(right+1), x)) {
                left--;
            } else if (left == arr.begin()) {
                right++;
            } else if (right+1 == arr.end()) {
                left--;
            } else {
                right++;
            }
        }
        
        std::vector<int> result(left, right+1);
        return result;
    }
};