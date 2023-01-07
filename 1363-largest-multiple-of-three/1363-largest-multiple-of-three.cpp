class Solution {
public:
    string calc(vector<int>& digits) {
        int sum = 0;
        sort(digits.begin(), digits.end());
        for(int i : digits) {
            sum += i;
        }
        
        string ans = "";
        
        if(sum%3==0) {
            for(int i : digits) ans += to_string(i);
        } 
        else if(sum%3==1) {
            bool f1 = false;
            for(int i : digits) {
                if(i%3==1) {
                    f1 = true;
                    break;
                }
            }
            if(f1) {
                int count = 0;
                for(int i : digits) {
                    if(i%3==1 and count == 0) {
                        count++;
                        continue;
                    }
                    ans += to_string(i);
                }
            }
            else {
                int count = 0;
                for(int i : digits) {
                    if(i%3==2) count++;
                }
                if(count >= 2) {
                    count = 0;
                    for(int i : digits) {
                        if(i%3==2 and count < 2) {
                            continue;
                        }
                        ans += to_string(i);
                    }
                }
            }
        } 
        else if(sum%3==2) {
            bool f1 = false;
            for(int i : digits) {
                if(i%3==2) {
                    f1 = true;
                    break;
                }
            }
            if(f1) {
                int count = 0;
                for(int i : digits) {
                    if(i%3==2 and count == 0) {
                        count++;
                        continue;
                    }
                    ans += to_string(i);
                }
            } 
            else {
                int count = 0;
                for(int i : digits) {
                    if(i%3==1) count++;
                }
                if(count >= 2) {
                    count = 0;
                    for(int i : digits) {
                        if(i%3==1 and count < 2) {
                            continue;
                        }
                        ans += to_string(i);
                    }
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