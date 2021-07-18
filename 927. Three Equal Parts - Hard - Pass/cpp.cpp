class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        if (arr.size() < 3) {
            return {-1, -1};
        }
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i]) {
                count++;
            }
        }
        
        if (count % 3 != 0) {
            return {-1, -1};
        } else if (count == 0) {
            return {0, 2};
        }
        
        int suffixZeros = 0;
        for (int i = arr.size()-1; arr[i] != 1; i--) {
            suffixZeros++;
        }
        
        int firstBlank = 0, secondBlank = -1;
        int currCount = 0;
        int i = 0;
        while (currCount < count / 3) {
            if (arr[i++]) {
                currCount++;
            }
        }
        firstBlank = i;
        while (currCount < count / 3 * 2) {
            if (arr[i++]) {
                currCount++;
            }
        }
        secondBlank = i;
        
        int zeroCount = 0;
        while (zeroCount < suffixZeros) {
            if (arr[firstBlank++] || arr[secondBlank++]) {
                return {-1, -1};
            }
            zeroCount++;
        }
        
        for (int i = firstBlank-1, j = secondBlank-1, k = arr.size()-1; i >= 0 && j >= firstBlank && k >= secondBlank; i--, j--, k--) {
            if (arr[i] != arr[j] || arr[i] != arr[k]) {
                return {-1, -1};
            }
        }
        
        return {firstBlank-1, secondBlank};
    }
};
