class RandomizedCollection {
private:
    std::vector<std::vector<int> > v;
    std::unordered_map<int, int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        v.clear();
        mp.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        
        if (mp.find(val) == mp.end() || mp[val] == -1) { 
            v.push_back({val, -1, -1});
        } else {
            v[mp[val]][2] = v.size();
            v.push_back({val, mp[val], -1});
            res = false;
        }
        //std::cout << "insert " << val << " " << mp[val] << std::endl;
        mp[val] = v.size()-1;
        
        return res;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val] == -1) {
            return false;
        }
//         for (int i = 0; i < v.size(); i++) {
//             std::cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << std::endl;
//         }
        
//         std::cout << "######" << std::endl;
        if (mp[val] != v.size()-1) {
            const std::vector<int> & currBack = v.back();
            
            if (currBack[1] != -1) {
                v[currBack[1]][2] = mp[val];
            }
            if (currBack[2] != -1) {
                v[currBack[2]][1] = mp[val];
            }
            if (mp[currBack[0]] == v.size()-1) {
                mp[currBack[0]] = mp[val];
            }
            
            std::swap(v.back(), v[mp[val]]);
        }
        const std::vector<int> & delBack = v.back();
        if (delBack[1] != -1) {
            v[delBack[1]][2] = -1;
        }
        mp[val] = delBack[1];

        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()][0];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
