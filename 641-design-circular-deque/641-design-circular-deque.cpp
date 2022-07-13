class MyCircularDeque {
public:
    
    int front ,rear, size;
    vector<int> dq;
    
    MyCircularDeque(int k) {
        size = 0;
        dq = vector<int>(k);
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        if(size==0){
            front = 0;
            rear = 0;
            size = 1;
            dq[front] = value;
            return true;
        }
        
        if(size==dq.size()){
            return false;
        }
        
        if(front==0){
            front = dq.size() - 1;
            dq[front] = value;
        }
        else{
            --front;
            dq[front] = value;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==0){
            front = dq.size()-1;
            rear = dq.size()-1;
            dq[front] = value;
            size = 1;
            return true;
        }
        if(size==dq.size())
            return false;
        
        rear++;
        rear %= dq.size();
        dq[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0)
            return false;
        front++;
        front%=dq.size();
        --size;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)
            return false;
        
        if(rear == 0)
            rear = dq.size()-1;
        else
            --rear;
        --size;
        return true;
    }
    
    int getFront() {
        if(size==0)
            return -1;
        
        return dq[front];
    }
    
    int getRear() {
        if(size==0)
            return -1;
        
        return dq[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==dq.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */