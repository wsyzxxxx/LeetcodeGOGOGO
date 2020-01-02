class Trie {
private:
    class TrieNode {
    private:
        TrieNode * nodes[26];
        bool endMark;
    public:
        TrieNode() : endMark(false) {
            for (int i = 0; i < 26; i++) {
                nodes[i] = NULL;
            }
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete nodes[i];
            }
        }
        bool isEnd() {
            return endMark;
        }
        void setEnd() {
            endMark = true;
        }
        TrieNode * get(char c) {
            return nodes[c - 'a'];
        }
        void put(TrieNode * root, char c) {
            if (nodes[c - 'a'] != NULL) {
                delete nodes[c - 'a'];
            }
            nodes[c - 'a'] = root;
        }
    };

private:
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * currNode = root;
        for (char c : word) {
            if (currNode->get(c) == NULL) {
                currNode->put(new TrieNode(), c);
            }
            currNode = currNode->get(c);
        }
        currNode->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * currNode = root;
        for (char c : word) {
            if (currNode->get(c) == NULL) {
                return false;
            }
            currNode = currNode->get(c);
        }
        return currNode->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * currNode = root;
        for (char c : prefix) {
            if (currNode->get(c) == NULL) {
                return false;
            }
            currNode = currNode->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
