class Solution {
public:
    bool calc(int i, int &mask, vector<int> &ans, int size, int n) {
        if(i >= size or mask == (1<<n)) return true;
        
        if(ans[i] != -1) return calc(i+1, mask, ans, size, n);
        
        for(int j = n; j >= 1; j--) {
            if(((mask>>(j-1))&1) == 1) continue;
            
            if(j == 1) {
                ans[i] = j;
                mask = mask|(1<<(j-1));
                if(calc(i+1, mask, ans, size, n) == true) return true;
                mask = mask&(~(1<<(j-1)));
                ans[i] = -1;
            }
            else if(i+j<size and ans[i+j] == -1) {
                ans[i] = j;
                ans[i+j] = j;
                mask = mask|(1<<(j-1));
                int res = calc(i+1, mask, ans, size, n);
                
                if(res) return true;
                mask = mask&(~(1<<(j-1)));
                ans[i+j] = -1;
                ans[i] = -1;
            }
        }
        
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        int mask = 0;
        int size = 2*n - 1;
        vector<int> ans(size, -1);
        
        calc(0, mask, ans, size, n);
        return ans;
    }
};