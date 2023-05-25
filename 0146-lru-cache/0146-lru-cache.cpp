struct Node{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    map<int, Node*> mp;
    int size;
    Node *head;
    Node *tail;
    int currSize = 0;
    
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insertAfterHead(Node*node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }
    
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        currSize = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            Node* node = new Node(key, value);
            mp[key] = node;
            if(currSize < size) {
                insertAfterHead(node);
                currSize++;
            } else {
                int lastNodeKey = tail->prev->key;
                deleteNode(mp[lastNodeKey]);
                insertAfterHead(node);
                mp.erase(lastNodeKey);
            }
        } else {
            Node* node = mp[key];
            deleteNode(node);
            node->val = value;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */