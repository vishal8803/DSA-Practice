class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> prefix(n + 1); //no
        vector<int> suffix(n); //yes
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'N') {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i+1] = prefix[i];
            }
        }
        
        int t = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'Y') {
                t++;
            } 
            suffix[i] = t;
        }
        
        int hr = INT_MAX;
        int penalty = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            // cout<<prefix[i]<<" "<<suffix[i]<<endl;
            if(i == n - 1) {
                int total = prefix[i];
                if(s[i] == 'Y') total++;
                if(penalty > total) {
                    penalty = total;
                    hr = i;
                } else if(penalty == total) {
                    hr = min(hr,i);
                }
            } else {
                int total = prefix[i] + suffix[i];
                if(penalty > total) {
                    penalty = total;
                    hr = i;
                } else if(penalty == total) {
                    hr = min(hr,i);
                }
            }
        }
        
        int total = prefix[n];
        if(penalty > total) {
                    penalty = total;
                    hr = n;
                } else if(penalty == total) {
                    hr = min(hr,n);
                }
        return hr;
    }
};