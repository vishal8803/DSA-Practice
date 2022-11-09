class StockSpanner {
public:
    stack<pair<int,int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 0;
        while(st.size() > 0 and st.top().first <= price) {
            count += st.top().second;
            st.pop();
        }
        st.push({price, count+1});
        return count + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */