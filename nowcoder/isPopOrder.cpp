class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }
        if (pushV.empty()) {
            return true;
        }
        
        std::stack<int> stackData;
        
        int pushIndex = 0;
        int popIndex = 0;
        
        while (popIndex < popV.size()) {
            if (popV[popIndex] == pushV[pushIndex]) {
                popIndex++;
                pushIndex++;
            } else if (!stackData.empty() && popV[popIndex] == stackData.top()) {
                popIndex++;
                stackData.pop();
            } else if (pushIndex < pushV.size()) {
                stackData.push(pushV[pushIndex++]);
            } else {
                return false;
            }
        }
        
        return (pushIndex == pushV.size()) && stackData.empty();
    }
};
