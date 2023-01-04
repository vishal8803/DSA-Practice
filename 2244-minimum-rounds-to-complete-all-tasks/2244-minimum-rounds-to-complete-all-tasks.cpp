class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i : tasks) mp[i]++;
        int count = 0;
        
        while(mp.size() > 0) {
            auto it = mp.begin();
            int elem = it->first;
            int freq = it->second;
            if(freq%3==0) {
                count += freq/3;
                mp.erase(elem);
            }  else if(freq == 2 or freq == 4) {
                count += freq/2;
                mp.erase(elem);
            } else {
                if(freq == 1) return -1;
                mp[elem] = 4;
                count += freq/3 - 1;
            }
        }
        return count;
    }
};