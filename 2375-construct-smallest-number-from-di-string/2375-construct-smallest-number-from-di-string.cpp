class Solution {
public:
    void calc(string pattern, int i, vector<bool> &used, string &ans, string temp, int prev) {
        if(i==pattern.size()) {
            // cout<<temp<<endl;
            if(ans == "" || ans > temp) ans = temp;
            return;
        }
        
        if(pattern[i]=='I') {
            if(prev==-1) {
                for(int k = 1; k <= 9; k++) {
                    for(int j = k+1; j<=9; j++) {
                        if(!used[j]){
                            used[j] = true;
                            used[k] = true;
                            calc(pattern, i+1, used, ans, temp + to_string(k) + to_string(j), j);
                            used[j] = false;
                            used[k] = false;
                        }
                    }
                }
            } else {
                for(int j = prev + 1; j <= 9; j++) {
                    if(!used[j]) {
                        used[j] = true;
                        calc(pattern, i+1, used, ans, temp + to_string(j), j);
                        used[j] = false;
                    }
                }
            }
        } 
        else{
            if(prev==-1) {
                for(int k = 1; k <= 9; k++) {
                    for(int j = k-1; j>=1; j--) {
                        if(!used[j]){
                            used[j] = true;
                            used[k] = true;
                            calc(pattern, i+1, used, ans, temp + to_string(k) + to_string(j), j);
                            used[j] = false;
                            used[k] = false;
                        }
                    }
                }
            } else {
                for(int j = prev - 1; j >= 1; j--) {
                    if(!used[j]) {
                        used[j] = true;
                        calc(pattern, i+1, used, ans, temp + to_string(j), j);
                        used[j] = false;
                    }
                }
            }
        }
    }
    
    string smallestNumber(string pattern) {
        string ans = "";
        vector<bool> used(10);
        calc(pattern, 0, used, ans, "", -1);
        return ans;
    }
};