// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
    private:
        map<int,Node*> mp;
        Node *head, *tail;
        int size,csize;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size = cap;
        head=NULL;
        tail=NULL;
        csize=0; 
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(csize==0)
            return -1;
            
        if(mp.find(key) == mp.end())
            return -1;
            
        Node* temp = mp[key];
        if(csize==1 || size==1)
            return temp->val;
            
        if(temp==head){
            head = head->next;
            head->prev = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            return temp->val;
        }
        else if(temp==tail){
            return temp->val;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            return temp->val;
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(size==1){
            if(mp.find(key) != mp.end()){
                Node* temp = mp[key];
                temp->val = value;
            }else{
                Node* n = new Node(key,value);
                if(csize==0){
                    head = n;
                    tail = n;
                    mp[key] = n;
                    csize = 1;
                }else{
                    mp.erase(head->key);
                    mp[key] = n;
                    head = n;
                    tail = n;
                }
            }
            return;
        }
        
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            temp->val = value;
            
            if(csize==1 || size==1)
            return;
            
            if(temp==head){
                head = head->next;
                head->prev = NULL;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
            else if(temp==tail){return;}
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                
            }
            return;
        }
        Node* newNode = new Node(key,value);
        mp[key] = newNode;
        
        if(head==NULL){
            head = newNode;
            tail = newNode;
            csize = 1;
            return;
        }
        
        if(csize==size){
            mp.erase(head->key);
            head = head->next;
            head->prev = NULL;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        } 
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        csize++;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends