class Solution {
public:
    void calc(int n, int k, set<int> &st, int prev, int num) {
        if(prev<0 || prev>=10) return;
        if(n==0) {
            st.insert(num);
            return;
        }
        
        calc(n-1,k,st, prev+k, num*10+prev);
        calc(n-1,k,st, prev-k, num*10+prev);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> temp;
        set<int> st;
        for(int i = 1; i <= 9; i++) {
            calc(n,k,st,i,0);
        }
        for(auto it = st.begin(); it != st.end(); it++) {
            temp.push_back(*it);
        }
        
        return temp;
    }
};