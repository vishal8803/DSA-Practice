class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        prefix[0] = !grumpy[0]?customers[0]:0;
        suffix[n-1] = !grumpy[n-1]?customers[n-1]:0;
        
        for(int i = 1; i < grumpy.size(); i++) {
            prefix[i] = prefix[i-1];
            if(!grumpy[i]) {
                prefix[i] += customers[i];
            }
        }
        
        for(int i = n-2; i>=0; i--) {
            suffix[i] = suffix[i+1];
            if(!grumpy[i]) {
                suffix[i] += customers[i];
            }
        }
        
        // for(int i : prefix) cout<<i<<" ";
        // cout<<endl;
        // for(int i : suffix) cout<<i<<" ";
        // cout<<endl;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while(j<minutes) {
            sum += customers[j++];
        }
        
        int ans = sum + (j<n?suffix[j]:0);
        
        while(j<n) {
            sum += customers[j];
            sum -= customers[i];
            j++;
            i++;
            
            int tempAns = sum + ( i-1>=0?prefix[i-1]:0) + (j<n?suffix[j] : 0);
            ans = max(ans, tempAns);
        }
        
        return ans;
    }
};