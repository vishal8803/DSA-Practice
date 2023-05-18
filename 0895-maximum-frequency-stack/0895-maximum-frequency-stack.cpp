class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> pq;
    int count = 0;
    unordered_map<int,int> freq;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        pq.push({++freq[val], {++count, val}});
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        freq[val.second.second]--;
        return val.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */