class StockPrice {
public:
    map<int,int> mp;
    map<int,int> st;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)==mp.end()) {
            mp[timestamp] = price;
            st[price]++;
        } else {
            int t = mp[timestamp];
            mp[timestamp] = price;
            st[t]--;
            if(st[t]==0) st.erase(t);
            st[price]++;
        }
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return st.rbegin()->first;
    }
    
    int minimum() {
        return st.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */