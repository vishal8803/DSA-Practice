class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp1;
        for(char c :s1){
            mp1[c]++;
        }
        
        map<char,int> mp2;
        int i=0,j=0;
        while(j<s2.length()){
            mp2[s2[j]]++;
            if(j-i+1<s1.length()){
                j++;
            }else if(j-i+1==s1.length()){
                if(mp1==mp2)
                    return true;
                
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0){
                    mp2.erase(s2[i]);
                }
                i++;
                j++;
            }
        }
        return false;
    }
};