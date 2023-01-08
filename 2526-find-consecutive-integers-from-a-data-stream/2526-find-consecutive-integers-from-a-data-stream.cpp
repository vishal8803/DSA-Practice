class DataStream {
public:
    deque<int> dq;
    map<int,int> mp;
    int k, value;
    
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        dq.push_back(num);
        mp[num]++;
        
        if(dq.size() < k) return false;
        
        int elem = dq.front();
        dq.pop_front();
        bool ans = false;
        
        if(mp.size() == 1 and mp.begin()->first == value) ans = true;
        
        mp[elem]--;
        if(mp[elem] == 0) mp.erase(elem);
        return ans;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */