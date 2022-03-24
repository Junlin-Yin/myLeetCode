class LRUCache {
    int size, capacity;
    struct LRUNode {
        int key;
        int val;
        LRUNode* prev;
        LRUNode* next;
        LRUNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
        LRUNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, LRUNode*> hash;
    LRUNode* head, *tail;

public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->head = new LRUNode();
        this->tail = new LRUNode();
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->hash.clear();
    }
    
    void removeNode(LRUNode* p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    void insertTail(LRUNode* p) {
        p->next = this->tail;
        p->prev = this->tail->prev;
        this->tail->prev->next = p;
        this->tail->prev = p;           
    }
    
    int get(int key) {
        int ret = -1;
        if(this->hash.find(key) != this->hash.end()){
            LRUNode* p = this->hash[key];
            removeNode(p);
            insertTail(p);
            ret = p->val;
        }
        return ret;
    }
    
    void put(int key, int value) {
        if(this->hash.find(key) != this->hash.end()){
            LRUNode* p = this->hash[key];
            removeNode(p);
            insertTail(p);
            p->val = value;
        }else{
            if(this->size == this->capacity){
                LRUNode* lru = this->head->next;
                removeNode(lru);
                this->hash.erase(lru->key);
                delete lru;
            }else{
                ++this->size;
            }
            LRUNode* p = new LRUNode(key, value);
            insertTail(p);
            this->hash[key] = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */