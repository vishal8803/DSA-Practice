class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int i = 0;
        int j = 0;
        string ans = "";
        while(i < s1.length() && j < s2.length()){
            ans += s1[i];
            ans += s2[j];
            i++;
            j++;
        }
        
        if(i<s1.length()){
            ans += s1.substr(i);
        }
        
        if(j<s2.length()){
            ans += s2.substr(j);
        }
        
        return ans;
    }
};