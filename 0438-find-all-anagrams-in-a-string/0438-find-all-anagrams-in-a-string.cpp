class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp;
        for(char c : p){
            mp[c]++;
        }
        map<char,int> temp;
        int i=0,j=0;
        vector<int> ans;
        while(j<s.length()){
            temp[s[j]]++;
           
            if(j-i+1<p.length()){
                j++;
            }else if(j-i+1==p.length()){
                if(temp==mp){
                    ans.push_back(i);
                }
                temp[s[i]]--;
                if(temp[s[i]]==0)
                    temp.erase(s[i]);
                
                i++;
                j++;
            }
        }
        return ans;
    }
};