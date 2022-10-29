class Solution {
public:
    int getGreaterOrEqual(vector<int> &v, int t) {
        
        int st = 0;
        int end = v.size() - 1;
        
        int res = v.size();
        
        while(st <= end) {
            
            int mid = (st + end) / 2;
            
            if(v[mid]==t) return v[mid];
            else if(v[mid] > t) {
                res = v[mid];
                end = mid-1;
                
            } else {
                st = mid + 1;
            }
            
        }
        
        return res;
    }
    
    int getSmallerOrEqual(vector<int> &v, int t) {
        int st = 0;
        int end = v.size() - 1;
        int res = -1;
        while(st <= end) {
            int mid = (st + end) / 2;
            if(v[mid] == t) return v[mid];
            else if(v[mid] > t) {
                
                end = mid-1;
            } else {
                res = v[mid];
                st = mid + 1;
            }
        }
        
        return res;
    }
    
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> braces;
        vector<int> prefix;
        int count = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i]=='|')
                braces.push_back(i);
            else count++;
            
            prefix.push_back(count);
        }
        
        vector<int> ans;
        for(auto q : queries) {
            int lt = q[0];
            int rt = q[1];
            
            int l = getGreaterOrEqual(braces, lt);
            int r = getSmallerOrEqual(braces, rt);
            
            if(l <= r) {
                if(l==0) {
                    ans.push_back(prefix[r]);
                } else ans.push_back(prefix[r] - prefix[l-1]);
            } else ans.push_back(0);
        }
        
        return ans;
    }
};