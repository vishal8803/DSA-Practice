class Solution {
public:
    void extractDigitLogsString(vector<string> &A, vector<string> &digitLogs, vector<string> &letterLogs) {
    
    for(string s : A) {
        int i = 0;
        while(i<s.length() && s[i] != ' '){
            i++;
        }
        i++;
        if(s[i]>='0' && s[i]<='9'){
            digitLogs.push_back(s);
        }else{
            letterLogs.push_back(s);
        }
    }
}
    vector<string> reorderLogFiles(vector<string> &A) {
    vector<string> digitLogs, letterLogs;
    extractDigitLogsString(A, digitLogs, letterLogs);
    
    sort(letterLogs.begin(), letterLogs.end(),[&](string s1, string s2){
        int i1 = 0;
        int i2 = 0;
        while(i1 < s1.length() && s1[i1] != ' '){
            i1++;
        }
        while(i2 < s2.length() && s2[i2] != ' '){
            i2++;
        }
        string t1 = s1.substr(i1+1);
        string t2 = s2.substr(i2+1);
        
        if(t1 == t2){
            return s1.substr(0,i1) < s2.substr(0,i2);
        }
        
        return t1 < t2;
    });
    
    vector<string> ans;
    
    for(string log : letterLogs){
        ans.push_back(log);
    }
    
    for(string log : digitLogs){
        ans.push_back(log);
    }
    
    return ans;
}
};