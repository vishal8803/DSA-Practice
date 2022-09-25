class MyCircularQueue {
public:
    vector<int> q;
    int size;
    int front,rear;
    
    MyCircularQueue(int k) {
        q = vector<int>(k);
        size = 0;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(size==0){
            q[0] =(value);
            size++;
            front = 0;
            rear = 0;
            return true;
        }
        if(size == q.size())
            return false;
        
        rear++;
        rear%=q.size();
        q[rear] = value;
        size++;
        
        return true;
    }
    
    bool deQueue() {
        if(size==0)
            return false;
        
        front++;
        front%=q.size();
        size--;
        return true;
        
    }
    
    int Front() {
        if(size==0)
            return -1;
        
        return q[front];
    }
    
    int Rear() {
        if(size==0)
            return -1;
        
        return q[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */