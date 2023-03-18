class BrowserHistory {
public:
    struct Node{
        string data;
        Node* next;
        Node* prev;
        Node(string val){
            data = val;
            next = NULL;
            prev = NULL;
        }
    };
    Node* head;
    Node* tail;
    Node* curr;
    BrowserHistory(string homepage) {
        head = new Node("");
        tail = new Node("");
        Node* r = new Node(homepage);
        head->next = r;
        r->prev = head;
        r->next = tail;
        tail->prev = r;
        curr = head->next;
    }
    
    void visit(string url) {
        Node* n = new Node(url);
        curr->next = n;
        n->prev = curr;
        n->next = tail;
        tail->prev = n;
        curr = curr->next; 
    }
    
    string back(int steps) {
        while(curr->prev != head && steps>0){
            curr = curr->prev;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(curr->next != tail && steps>0){
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */