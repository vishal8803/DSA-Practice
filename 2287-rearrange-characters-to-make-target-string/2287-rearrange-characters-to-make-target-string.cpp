class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq1(26), freq2(26);
        for(char ch : s){
            freq1[ch-'a']++;
        }
        
        for(char ch : target){
            freq2[ch-'a']++;
        }
        
        int mn = INT_MAX;
        
        for(char ch : target){
            if(freq1[ch-'a']==freq2[ch-'a'])
                mn = min(mn,1);
            else if(freq2[ch-'a'] > freq1[ch-'a'])
                mn = min(mn,0);
            else
                mn = min(mn,freq1[ch-'a']/freq2[ch-'a']);
        }
        
        return mn;
    }
};