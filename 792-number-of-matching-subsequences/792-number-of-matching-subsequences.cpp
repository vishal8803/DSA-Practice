class Solution {
public:
    bool isSubsequence(string s1, string s2){
        int i = 0;
        int j = 0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                j++;
            }
            i++;
        }
        return j==s2.length();
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string,int> mp;
        
        for(string t : words){
            mp[t]++;
        }
        
        for(auto it : mp){
            if(isSubsequence(s,it.first))
                count+=it.second;
        }
        
        return count;
    }
};