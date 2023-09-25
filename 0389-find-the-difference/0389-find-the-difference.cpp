class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp;
        for(char c : t){
            mp[c]++;
        }
        
        for(char c : s){
            mp[c]--;
            if(mp[c]==0){
                mp.erase(c);
            }
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            return it->first;
        } 
        return '#';
    }
};