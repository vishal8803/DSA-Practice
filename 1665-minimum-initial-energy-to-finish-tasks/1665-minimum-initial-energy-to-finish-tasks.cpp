class Solution {
public:
    bool isPossible(vector<vector<int>> &tasks, int t) {
        
        for(auto task : tasks) {
            if(task[1] > t) return false;
            t -= task[0];
        }
        
        return true;
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int> &v1, vector<int> &v2) {
            return v1[1] - v1[0] > v2[1] - v2[0];
        });
        
        int st = 0;
        int end = 1e9;
        int res;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(isPossible(tasks, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return res;
    }
};