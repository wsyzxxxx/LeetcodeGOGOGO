class Trie {
private:
    struct TrieNode {
        bool isFinal;
        TrieNode * children[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isFinal = false;
        }
    };
    
    TrieNode * root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) {
                curr->children[word[i]-'a'] = new TrieNode();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->isFinal = true;
    }
    
    bool search(string word) {
        TrieNode * curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) {
                return false;
            }
            curr = curr->children[word[i]-'a'];
        }
        return curr->isFinal == true;
    }
    
    bool startsWith(string word) {
        TrieNode * curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) {
                return false;
            }
            curr = curr->children[word[i]-'a'];
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