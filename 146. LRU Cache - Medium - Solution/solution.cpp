class LRUCache {
private:
    class ListNode {
    public:
        int key;
        int value;
        ListNode * prev;
        ListNode * next;
        ListNode(int _key, int _value, ListNode * _prev, ListNode * _next) :
                key(_key), value(_value), prev(_prev), next(_next) {}
        ListNode(int _key, int _value) : key(_key), value(_value) {}
    };
    std::unordered_map<int, ListNode *> mp;
    int size;
    int capacity;
    ListNode * head;
    ListNode * tail;
public:
    LRUCache(int _capacity) : size(0), capacity(_capacity) {
        if (capacity == 0) {
            throw std::exception();
        }
        head = new ListNode(0, 0, NULL, NULL);
        tail = new ListNode(0, 0, head, NULL);
        head->next = tail;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        ListNode * curr = mp[key];
        if (curr != head->next) {
        curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = head->next;
            curr->prev = head;
            head->next->prev = curr;
            head->next = curr;
        }
        return curr->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            ListNode * curr = mp[key];
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = head->next;
            head->next->prev = curr;
            curr->prev = head;
            head->next = curr;
            curr->value = value;
            return;
        }
        
        if (size == capacity) {
            ListNode * curr = tail->prev;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            mp.erase(curr->key);
            delete curr;
        }
        ListNode * curr = new ListNode(key, value, head, head->next);
        head->next->prev = curr;
        head->next = curr;
        mp[key] = curr;
        if (size < capacity) {
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
