class Solution {
public:
    int calc(vector<int> &a, int target) {
        int st = 0;
        int end = a.size() - 1;
        int res = -1;
        
        while(st <= end) {
            int mid = (st+end) / 2;
            if(a[mid] > target) {
                res = mid;
                 end = mid - 1;
            } else {
                
                st = mid + 1;
            }
        }
        
        if(res == -1) return 0;
        
        return a.size() - res;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> fw;
        
        for(int i = 0; i < n; i++) {
            string s = words[i];
            vector<int> freq(26,0);
            for(char ch : s) {
                freq[ch-'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(freq[i] != 0) {
                    
                    fw.push_back(freq[i]);
                    break;
                }
            }
        }
        
        sort(fw.begin(), fw.end());
        int m = queries.size();
        vector<int> ans;
        
        for(int i = 0; i < m; i++) {
            string q = queries[i];
            vector<int> freq(26,0);
            for(char ch : q) {
                freq[ch-'a']++;
            }
            int count;
            for(int i = 0; i < 26; i++) {
                if(freq[i] != 0) {
                    count = freq[i];
                    break;
                }
            }
            
            ans.push_back(calc(fw,count));
        }
        
        return ans;
    }
};