class Solution {
public:
    int maxEvents(vector<vector<int>>& v) {
        int mx = INT_MIN;
        sort(v.begin(), v.end(), [&](vector<int> &p1, vector<int> &p2){
            if(p1[1] < p2[1]) return true;
            else if(p1[1]==p2[1]) return p1[0] < p2[0];
            return false;
        });
        
        int N = v.size();
        for(int i = 0; i < N; i++){
            mx = max(mx,v[i][0]);
            mx = max(mx,v[i][1]);
        }
        
        set<int> st;
        
        for(int i = 1; i<=mx+1; ++i){
            st.insert(i);
        }
        
        int count = 0;
        
        for(int i = 0 ; i < N; ++i){
            auto it = st.lower_bound(v[i][0]);
            if(it==st.end() || *it > v[i][1]){
                continue;
            }else{
                ++count;
                st.erase(*it);
            }
        }
        return count;
        
    }
};