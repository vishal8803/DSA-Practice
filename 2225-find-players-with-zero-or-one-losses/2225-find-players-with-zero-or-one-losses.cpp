class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loose;
        map<int,int> wins;
        
        for(vector<int> match : matches){
            int win = match[0];
            int lost = match[1];
            
            wins[win]++;
            loose[lost]++;
        }
        
        vector<int> a1,a2;
        
        for(auto it = wins.begin(); it != wins.end(); it++){
            int elem = it->first;
            if(loose[elem]==0){
                a1.push_back(elem);
            }
        }
        
        for(auto it = loose.begin(); it != loose.end(); it++){
            if(it->second==1){
                a2.push_back(it->first);
            }
        }
        
        vector<vector<int>> ans;
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};