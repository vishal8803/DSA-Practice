class Solution {
public:
    bool isPossible(string &s, string &p, vector<int>& removable, int mid) {
        vector<bool> visited(s.size(), 0);
        for(int i = 0; i < mid; i++) {
            visited[removable[i]] = true;
        }
        
        int i = 0;
        int j = 0;
        
        while(i < s.size() and j < p.size()) {
            if(visited[i]) {i++; continue;}
            
            if(s[i] == p[j]) {
                i++;
                j++;
            } else i++;
        }
        
        return j >= p.size();
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int st = 0;
        int end = removable.size() - 1;
        int res = 0;
        // cout<<isPossible(s, p, removable, 14)<<endl;
        // return 0;
        while(st <= end) {
            int mid = (st + end) / 2;
            if(isPossible(s, p, removable, mid + 1)) {
                res= mid + 1;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};