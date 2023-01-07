class Solution {
public:
    string calc(vector<int>& digits) {
        int sum = 0;
        int c1 = 0, c2 = 0;
        
        sort(digits.begin(), digits.end());
        for(int i : digits) {
            sum += i;
            
            if(i%3==1) c1++;
            else if(i%3==2) c2++;
        }
        
        string ans = "";
        
        if(sum%3==0) {
            for(int i : digits) ans += to_string(i);
        } 
        else if(sum%3==1) {
            if(c1>0) {
                int count = 0;
                for(int i : digits) {
                    if(i%3==1 and count == 0) {
                        count++;
                        continue;
                    }
                    ans += to_string(i);
                }
            }
            else if(c2 >= 2) {
                int count = 0;
                for(int i : digits) {
                    if(i%3==2 and count < 2) {
                        count++;
                        continue;
                    }
                    ans += to_string(i);
                }
            }
        } 
        else if(sum%3==2) {
            if(c2 > 0) {
                int count = 0;
                for(int i : digits) {
                    if(i%3==2 and count == 0) {
                        count++;
                        continue;
                    }
                    ans += to_string(i);
                }
            } 
            else if(c1 >= 2) {
                int count = 0;
                for(int i : digits) {
                    if(i%3==1 and count < 2) {
                        count++;
                        continue;
                    }
                    ans += to_string(i);
                }
            }
        }
        
        sort(ans.begin(), ans.end(), greater<char>());
        return ans;
        
    }
    
    
    string largestMultipleOfThree(vector<int> &digits) {
        string ans = calc(digits);
        int i = 0;
        while(i < ans.size() - 1 and ans[i] == '0') i++;
        
        return ans.substr(i);
    }
};