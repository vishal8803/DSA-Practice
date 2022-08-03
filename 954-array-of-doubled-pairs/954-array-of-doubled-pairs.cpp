class Solution
{
    public:
        bool canReorderDoubled(vector<int> &arr)
        {
            map<int, int> mp;

            for (int i: arr) mp[i]++;
            
            while(mp.size()>0) {
                int elem = mp.begin()->first;
                mp[elem]--;
                if(mp[elem]==0) mp.erase(elem);
                
                if(mp.find(2*elem) != mp.end()) {
                    mp[2*elem]--;
                    if(mp[2*elem]==0) mp.erase(2*elem);
                } else if( elem%2==0 && mp.find(elem/2) != mp.end()) {
                    mp[elem/2]--;
                    if(mp[elem/2]==0) mp.erase(elem/2);
                } else return false;
            }
            
            return true;
        }
};