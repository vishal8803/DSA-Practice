class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> booked(n, 0);
        vector<long long> avl(n, -1);
        
        sort(begin(meetings), end(meetings));
        
        for(auto &meeting : meetings) {
            int st = meeting[0];
            int end = meeting[1];
            int duration = end - st;
            
            int idx = -1;
            long long mn = 1e18;
            int mn_idx = -1;
            
            for(int i = 0; i < n; i++) {
                if(avl[i] == -1 or avl[i] <= st) {
                    idx = i;
                    break;
                }
                if(mn > avl[i]) {
                    mn = avl[i];
                    mn_idx = i;
                }
            }
            
            if(idx != -1) 
            {
                booked[idx]++;
                avl[idx] = st + duration;
            } else
            {
                booked[mn_idx]++;
                avl[mn_idx] += duration;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(booked[i] > booked[ans]) {
                ans = i;
            }
        }
        
        return ans;
    }
};