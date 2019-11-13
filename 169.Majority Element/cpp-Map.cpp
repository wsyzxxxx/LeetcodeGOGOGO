class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        std::map<int, int> storageMap;
        int n = nums.size() / 2;
        for (std::vector<int>::const_iterator it = nums.begin();
            it != nums.end(); ++it) {
            std::map<int, int>::iterator mit = storageMap.find(*it);
            if (mit != storageMap.end()) {
                mit->second++;
                if (mit->second > n)
                    return mit->first;
            } else
                storageMap.insert(pair<int, int>(*it, 1));
        }
        
        return 0;
    }
};
