class Solution {
public:
    int get(char ch){
        if(ch=='a')return 0;
        else if(ch=='e')return 1;
        else if(ch=='i')return 2;
        else if(ch=='o')return 3;
        else if(ch=='u')return 4;
        return -1;
    }
    int findTheLongestSubstring(string s) {
        map<int,int> mp;
        mp[0] = -1;
        
        int mask = 0;
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            int val = get(ch);
            if(val != -1){
                mask = mask^(ch);
            }
            if(mp.find(mask) != mp.end()){
                ans = max(ans, i-mp[mask]);
            }else{
                mp[mask] = i;
            }
        }
        return ans;
    }
};