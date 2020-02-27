class RandomizedSet {
private:
    // struct ListNode {
    //     int val;
    //     ListNode * prev;
    //     ListNode * next;
    //     ListNode(int _val): val(_val), prev(nullptr), next(nullptr) {}
    // };
    // ListNode * head = nullptr;
    // ListNode * tail = nullptr;
    std::vector<int> v;
    std::unordered_map<int, int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        v.clear();
        mp.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end() && mp[val] != -1) {
            return false;
        }
        // if (head == nullptr) {
        //     head = tail = new ListNode(val);
        //     mp[val] = head;
        // } else {
        //     head->prev = new ListNode(val);
        //     head->prev->next = head;
        //     head = head->prev;
        //     mp[val] = head;
        // }
        v.push_back(val);
        mp[val] = v.size()-1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val] == -1) {
            return false;
        }
        // if (head == mp[val]) {
        //     head = head->next;
        // }
        // if (tail == mp[val]) {
        //     tail = tail->prev;
        // }
        // if (mp[val]->prev) {
        //     mp[val]->prev->next = mp[val]->next;
        // }
        // if (mp[val]->next) {
        //     mp[val]->next->prev = mp[val]->prev;
        // }
        // delete mp[val];
        // mp[val] = nullptr;
        if (val != v.back()) {
            mp[v.back()] = mp[val];
            std::swap(v.back(), v[mp[val]]);
        }
        mp[val] = -1;
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
//         if (head == nullptr) {
//             return -1;
//         }
        
//         int res = head->val;
//         if (head->next) {
//             ListNode * temp = head->next;
//             head->next->prev = nullptr;
//             head->prev = tail;
//             head->next = nullptr;
//             tail->next = head;
//             tail = head;
//             head = temp;
//         }
        
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
