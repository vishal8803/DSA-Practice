class Solution {
public:
    string getBinary(int num, int n) {
        string ans = "";
        while(num>0) {
            int r = num%2;
            num/=2;
            ans += to_string(r);
        }
        
        reverse(ans.begin(), ans.end());
        int t = ans.length();
        while(t<n) {
            ans = "0" + ans;
            t++;
        }
        return ans;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;
        
        for(string num : nums) {
            st.insert(num);
        }
        
        int n = nums.size();
        for(int i = 0; i < (1<<n); i++) {
            string t = getBinary(i,n);
            if(st.find(t) == st.end()) return t;
        }
        
        return "";
    }
};