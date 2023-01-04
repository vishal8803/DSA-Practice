class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i : tasks) mp[i]++;
        int count = 0;
        
        while(mp.size() > 0) {
            auto it = mp.begin();
            int elem = it->first;
            int freq = it->second;
            // cout<<elem<<" "<<freq<<endl;
            if(freq%3==0) {
                count += freq/3;
                mp.erase(elem);
            }  else if(freq%2==0) {
                if(freq == 2 || freq == 4) {
                    count += freq/2;
                    mp.erase(elem);
                    continue;
                }
                mp[elem] = freq - 3;
                    count++;
            } else {
                if(freq == 1) return -1;
                mp[elem] = freq - 3;
                    count++;
            }
        }
        return count;
    }
};