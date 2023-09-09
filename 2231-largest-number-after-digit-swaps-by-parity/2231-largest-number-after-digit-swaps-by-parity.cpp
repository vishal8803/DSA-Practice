class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<char> even, odd;
        
        for(char ch : s) {
            int n = (ch - '0');
            if(n%2) {
                odd.push_back(ch);
            } else {
                even.push_back(ch);
            }
        }
        
        sort(begin(even), end(even));
        sort(begin(odd), end(odd));
        reverse(begin(even), end(even));
        reverse(begin(odd), end(odd));
        
        int i = 0;
        int j = 0;
        
        string ans = "";
        for(char ch : s) {
            int n = (ch - '0');
            if(n%2) {
                ans += odd[i++];
            } else {
                ans += even[j++];
            }
        }
        return stoi(ans);
    }
};