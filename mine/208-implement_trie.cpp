class Trie {
private:
    struct TrieNode{
        bool isEnd;
        TrieNode* next[26];
        TrieNode() : isEnd(false) {
            for(int i = 0; i < 26; ++i) next[i] = nullptr;
        }
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(const char& c: word){
            if(!p->next[c-'a'])
                p->next[c-'a'] = new TrieNode();
            p = p->next[c-'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(const char& c: word){
            if(!p->next[c-'a']) return false;
            p = p->next[c-'a'];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(const char& c: prefix){
            if(!p->next[c-'a']) return false;
            p = p->next[c-'a'];
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