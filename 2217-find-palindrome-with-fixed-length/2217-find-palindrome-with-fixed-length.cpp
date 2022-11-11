class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int n) {
        vector<long long> res;
        
        for(int q : queries) {
            if(n == 1) {
                if(q > 9) {
                    res.push_back(-1);
                } else res.push_back(q);
                continue;
            }
            string s = to_string(q);
            
            if(pow(10, (n-1)/2)*9 < q) {
                res.push_back(-1);
                continue;
            }
            
            string ans(n,'#');
            
            int idx = (n-1)/2;
            int j = s.size() - 1;
            int t = pow(10, idx)*9;
            if(t == q) {
                string temp(n,'9');
                ans = temp;
                res.push_back(stol(ans));
                continue;
            }
            if(s[j] == '0') {
                
                
                q--;
                s = to_string(q);
                j = s.size() - 1;
                ans[idx--] = '9';
                j--;
            } else {
                ans[idx--] = (s[j--] - 1);
            }
            
            while(idx >= 0 and j >= 0) {
                ans[idx--] = s[j--];
            }
            if(ans[0] != '9') {
                ans[0] = (ans[0] + 1);
            }
            while(idx > 0) {
                ans[idx--] = '0';
            }
            
            while(idx >= 0) {
                ans[idx--] = '1';
            }
            
            int i = 0;
            j = n - 1;
            
            while(i < j) {
                ans[j--] = ans[i++];
            }
            
            res.push_back(stol(ans));
        }
        
        return res;
    }
};

/*
[1,2,3,4,5,90]
3
[2,4,6]
4
[928053739,72,86059860,90,622074924,831263840,8,10,43,13,54,870906009,64]
3
[392015495,5,4,1,425320571,565971690,3,7,6,3,506222280,468075092,5]
2
[94205982,719721292,1,588960619,794457264,134503655]
1
[1,2,3,4,5,90]
3

*/