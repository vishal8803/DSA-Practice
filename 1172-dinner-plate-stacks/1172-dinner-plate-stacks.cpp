class DinnerPlates {
public:
    vector<stack<int>> v;
    int mx;
    set<int> full, empty, sz;
    int i = 0;
    
    DinnerPlates(int capacity) {
        mx = capacity;
    }
    
    void push(int val) {
        if(empty.size() == 0) {
            if(sz.size() > 0) {
                int idx = *sz.begin();
                sz.erase(idx);
                v[idx].push(val);
                if(v[idx].size() == mx) {
                    full.insert(idx);
                } else {
                    empty.insert(idx);
                }
            }else {
                stack<int> st;
                st.push(val);
                v.push_back(st);
                if(st.size() == mx) {
                    full.insert(v.size() - 1);
                } else {
                    empty.insert(v.size() - 1);
                } 
            }
            
            return;
        }
        
        int idx = *empty.begin();
        v[idx].push(val);
        if(v[idx].size() == mx) {
            empty.erase(idx);
            full.insert(idx);
        }
        // cout<<empty.size()<<" "<<full.size()<<endl;
    }
    
    int pop() {
        if(full.size() == 0 and empty.size() == 0) return -1;
        
        int idx = -1;
        if(full.size() > 0) {
            idx = max(idx, *full.rbegin());
        }
        if(empty.size() > 0) {
            idx = max(idx, *empty.rbegin());
        }
        int ans = v[idx].top();
        
        if(v[idx].size() == mx) {
            full.erase(idx);
            v[idx].pop();
            if(v[idx].size() != 0) {
                empty.insert(idx);
            } else {
                sz.insert(idx);
            }
        } else {
            v[idx].pop();
            if(v[idx].size() == 0) {
                if(empty.find(idx) != empty.end()) {
                    empty.erase(idx);
                }
                sz.insert(idx);
            }
        }
        
        return ans;
    }
    
    int popAtStack(int idx) {
        if(idx > v.size() or v[idx].size() == 0) return -1;
        
        int ans = v[idx].top();
        if(v[idx].size() == mx) {
            full.erase(idx);
            v[idx].pop();
            if(v[idx].size() != 0) {
                empty.insert(idx);
            } else {
                sz.insert(idx);
            }
        } else {
            v[idx].pop();
            if(v[idx].size() == 0) {
                if(empty.find(idx) != empty.end()) {
                    empty.erase(idx);
                }
                sz.insert(idx);
            }
        }
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */