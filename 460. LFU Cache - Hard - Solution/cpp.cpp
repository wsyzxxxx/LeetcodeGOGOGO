class LFUCache {
private:
    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode * prev;
        ListNode * next; 
    };
    
    std::unordered_map<int, ListNode *> key2node;
    std::unordered_map<int, std::pair<ListNode *, ListNode *>> freq2list;
    int leastFreq;
    int cap;
public:
    LFUCache(int capacity) {
        this->leastFreq = 1;
        this->cap = capacity;
    }
    
    void remove(ListNode * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void update(int key) {
        ListNode * node = key2node[key];
        
        int freq = ++node->freq;
        remove(node);
        if (!freq2list.count(freq)) {
            ListNode * head = new ListNode{0, 0, 0, nullptr, nullptr};
            ListNode * tail = new ListNode{0, 0, 0, head, nullptr};
            head->next = tail;
            freq2list[freq] = {head, tail};
        }
        
        node->prev = freq2list[freq].second->prev;
        node->next = freq2list[freq].second;
        node->prev->next = node;
        node->next->prev = node;
        
        if (freq-1 == leastFreq && freq2list[leastFreq].first->next == freq2list[leastFreq].second) {
            leastFreq++;
        }
    }
    
    int get(int key) {
        if (cap == 0) {
            return -1;
        }
        if (key2node.find(key) == key2node.end()) {
            return -1;
        }
        //std::cout << "bleast" << leastFreq <<std::endl;
        update(key);
        //std::cout << "least" << leastFreq <<std::endl;
        return key2node[key]->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (key2node.count(key)) {
            key2node[key]->val = value;
            update(key);
            return;
        }
        
        if (key2node.size() == cap) {
            ListNode * td = freq2list[leastFreq].first->next;
            remove(td);
            key2node.erase(td->key);
            //delete td;
        }
        leastFreq = 1;
        if (!freq2list.count(leastFreq)) {
            ListNode * head = new ListNode{0, 0, 0, nullptr, nullptr};
            ListNode * tail = new ListNode{0, 0, 0, head, nullptr};
            head->next = tail;
            freq2list[leastFreq] = {head, tail};
        }
        ListNode * nd = new ListNode{key, value, leastFreq, freq2list[leastFreq].second->prev, freq2list[leastFreq].second};
        nd->prev->next = nd;
        nd->next->prev = nd;
        key2node[key] = nd;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */