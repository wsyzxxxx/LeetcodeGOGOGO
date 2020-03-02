class PhoneDirectory {
private:
    std::vector<int> nums;
    int currPos;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        nums.resize(maxNumbers);
        for (int i = 0; i < maxNumbers; i++) {
            nums[i] = (i+1) % maxNumbers;
        }
        currPos = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (nums[currPos] == -1) {
            return -1;
        }
        
        int res = currPos;
        currPos = nums[currPos];
        nums[res] = -1;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= nums.size()) {
            return false;
        }
        
        return nums[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= nums.size() || nums[number] != -1) {
            return;
        }
        
        nums[number] = currPos;
        currPos = number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
