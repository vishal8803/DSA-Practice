class Solution {
public:
    int numSplits(string s) {
        vector<int> prefix(26,0);
        vector<int> suffix(26,0);
        
        map<int,vector<int>> mp1;
        map<int,vector<int>> mp2;
        
        for(int i = 0; i < s.length(); i++) {
            prefix[s[i]-'a']++;
            mp1[i] = prefix;
        }
        
        for(int i = s.length() - 1; i >= 0; i--) {
            
            mp2[i] = suffix;
            suffix[s[i]-'a']++;
        }
        
        int count = 0;
        
        for(int i = 0; i < s.length(); i++) {
            int count1 = 0;
            int count2 = 0;
            
            vector<int> t1 = mp1[i];
            vector<int> t2 = mp2[i];
            
            for(int i : t1) {
                if(i > 0) count1++;
            }
            
            for(int i : t2) {
                if(i > 0) count2++;
            }
            
            if(count1==count2) count++;
        }
        
        return count;
    }
};