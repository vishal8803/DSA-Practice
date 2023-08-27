class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size()==2){
            if(stones[1]==1)
                return true;
            return false;
        }
        map<int,set<int>> mp;
        for(int i=0 ;i<stones.size(); i++){
            set<int> st;
            mp[stones[i]]=st;
        }
        
        if(mp.find(1)!=mp.end()){
            mp[1].insert(1);
            mp[1].insert(2);
        }
        
        for(int i=1; i<stones.size(); i++){
            set<int> st = mp[stones[i]];
            for(auto it = st.begin(); it!=st.end(); it++){
                int jump = *it;
                if(jump+stones[i]==stones[stones.size()-1])
                    return true;
                if(mp.find(jump+stones[i])!=mp.end()){
                    mp[jump+stones[i]].insert(jump-1);
                    mp[jump+stones[i]].insert(jump);
                    mp[jump+stones[i]].insert(jump+1);
                }
            }
        }
        return false;
    }
};