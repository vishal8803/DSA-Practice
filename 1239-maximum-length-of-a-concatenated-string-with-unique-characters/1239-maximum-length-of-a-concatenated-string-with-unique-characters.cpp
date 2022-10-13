class Solution {
public:
    
    int calc(vector<string> &arr, int i, vector<int> &freq) {
        if(i == arr.size()) return 0;
        
        bool flag = true;
        
        for(char ch : arr[i]) {
            if(freq[ch - 'a'] != 0) {
                flag = false;
            } 
            
            freq[ch-'a']++;
        }
        
        int ans = INT_MIN;
        
        if(flag) {
            ans = arr[i].size() + calc(arr, i+1, freq);
        }
        
        for(char ch : arr[i]) {
            freq[ch-'a']--;
        }
        
        ans = max(ans, calc(arr, i+1, freq));
        return ans;
    }
    
    
    int maxLength(vector<string>& arr) {
        vector<int> freq(26,0);
        return calc(arr, 0, freq);
    }
};