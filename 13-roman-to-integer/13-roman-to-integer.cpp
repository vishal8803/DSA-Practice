class Solution {
public:
    int romanToInt(string s) {
        vector<pair<char,int>> v = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        int n = s.length();
        
        for(int i = 0; i < s.length(); i++) {
            if(i+1<n && s[i]=='I' && s[i+1]=='V'){
                ans += 4;
                i+=1;
            }else if(i+1<n && s[i]=='I' && s[i+1]=='X'){
                ans += 9;
                i+=1;
            }else if(i+1<n && s[i]=='X' && s[i+1]=='L'){
                ans += 40;
                i+=1;
            }else if(i+1<n && s[i]=='X' && s[i+1]=='C'){
                ans += 90;
                i+=1;
            }else if(i+1<n && s[i]=='C' && s[i+1]=='D'){
                ans += 400;
                i+=1;
            }else if(i+1<n && s[i]=='C' && s[i+1]=='M'){
                ans += 900;
                i+=1;
            }else{
                for(auto j : v){
                    if(s[i]==j.first){
                        ans += j.second;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};