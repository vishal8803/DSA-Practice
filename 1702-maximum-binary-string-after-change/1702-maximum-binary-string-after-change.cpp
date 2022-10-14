class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        string ans(n,'1');
        int c = 0;
        
        for(int i = 0; i < n; i++) {
            if(binary[i]=='0') c++;
        }
        
        for(int i = 0; i < n; i++) {
            if(binary[i]=='0') {
                ans[i + c - 1] = '0'; 
                break;
            }
        }
        
        return ans;
    }
};