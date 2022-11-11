class Solution {
public:
    int calcSmaller(vector<vector<int>> &events, int target) {
        int res = -1;
        int st =0 ;
        int end = events.size() - 1;
        
        while(st <= end) {
            int mid = (st + end)/2;
            if(events[mid][1] >= target) {
                end = mid - 1;
            } else {
                res = mid;
                st = mid + 1;
            }
        }
        
        return res;
    }
    
    int calcGreater(vector<vector<int>> &events, int target) {
        int res = -1;
        int st = 0;
        int end = events.size() - 1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(events[mid][0] > target) { 
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        
        sort(events.begin(), events.end());
        int ans =INT_MIN;
        
        prefix[0] = events[0][2];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i], events[i][2]);
        }
        
        suffix[n-1] = events[n-1][2];
        for(int i = n-2; i >=0 ;i--) {
            suffix[i] = max(suffix[i+1], events[i][2]);
        }
        
        
        for(int i = 0; i < n; i++) {
            int idx1 = calcSmaller(events, events[i][0]);
            int idx2 = calcGreater(events, events[i][1]);
            // cout<<idx1 << " "<<idx2<<endl; 
            if(idx1 != -1 and idx2 != -1) {
                int res1 = events[i][2] + prefix[idx1];
                int res2 = events[i][2] + suffix[idx2];
                ans = max(ans, max(res1, res2));
            } else if(idx1 != -1) {
                ans = max(ans, events[i][2] + prefix[idx1]);
            } else if(idx2 != -1) {
                ans = max(ans, events[i][2] + suffix[idx2]);
            } else {
                ans = max(ans, events[i][2]);
            }
        }
        return ans;
    }
};