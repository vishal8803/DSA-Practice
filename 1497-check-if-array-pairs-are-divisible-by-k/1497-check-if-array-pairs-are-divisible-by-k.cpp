class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
        
        for(int i : arr) {
            freq[((i%k) + k)%k]++;
        }
        
        for(int i = 0; i < k; i++) {
            if(i==0) {
                if(freq[i]%2 != 0) return false;
            } else if(i == k - i) {
                if(freq[i]%2 != 0) return false;
            } else {
                if(freq[i] != freq[k - i]) return false;
            }
        }
        
        return true;
    }
};