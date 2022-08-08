class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        map<int,long long> mp;
        
        for(int task : tasks) {
            day++;
            
            if(mp.find(task)==mp.end()) {
                mp[task] = day;
            } else {
                long long prev = mp[task];
                if(day < (long long)(prev+space+1))
                    day = (long long)prev + space + 1;
                mp[task] = day;
            }
        }
        
        return day;
    }
};