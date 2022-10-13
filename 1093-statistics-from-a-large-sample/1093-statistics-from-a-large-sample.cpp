class Solution {
public:
    int kthElement(vector<pair<int,int>> &prefix, int k) {
        int st = 0;
        int end = prefix.size() - 1;
        int res = -1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            
            if(prefix[mid].second >= k) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return prefix[res].first;
    }
    
    vector<double> sampleStats(vector<int>& count) {
        vector<pair<int,int>> t, prefix;  // elem, freq
        int total = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mode,freq = 0;
        long long int elemsum = 0;
        
        for(int i = 0; i < 256; i++){
            if(count[i] != 0) {
                
                if(count[i] > freq) {
                    mode = i;
                    freq = count[i];
                }
                elemsum += (long long int)i*(long long int)count[i];
                t.push_back({i, count[i]});
                total += count[i];
                prefix.push_back({i,total});
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        // 191 199 204 204 204
        // for(int i = 0; i < prefix.size(); i++) {
        //     cout<<prefix[i].first<<" "<<prefix[i].second<<endl;
        // }
        
        int k = total/2;
        double mean = (double)elemsum/(double)total;
        
        
        double median;
        
        if(total % 2) {
            median = kthElement(prefix,k + 1);
        } else {
            median = (double)(kthElement(prefix,k) + kthElement(prefix,k+1))/2.0;
        }
        
        vector<double> ans = {(double)(mn), (double)(mx), mean, median, (double)(mode)};
        return ans;
    }
};