class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n==1)
            return citations[0]>0;
        
        sort(citations.begin(), citations.end());
        
        
        
        for(int i = n; i>=1; i--){
            int idx = lower_bound(citations.begin(), citations.end(),i) - citations.begin();
            int total = n - idx;
            if(total>=i)
                return i;
        }
        return 0;
    }
};