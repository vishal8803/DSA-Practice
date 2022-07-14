class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> f(26,500);
        
        for(int i = 0; i < order.length(); i++){
            f[order[i]-'a'] = i;
        }
        
        sort(s.begin(), s.end(), [&](char c1, char c2){
            if(f[c1-'a'] < f[c2-'a'])
                return true;
            return false;
        });
            
        return s;
    }
};