class Solution {
public:
    bool possible(vector<int> &tasks, vector<int> &workers, int pills, int strength, int k) {
        multiset<int> st;
        for(int i : workers) st.insert(i);
        
        for(int i = k-1; i >= 0; i--) {
            auto it = prev(st.end());
            if(tasks[i] <= *it) {
                st.erase(it);
            } else if(pills > 0 and st.lower_bound(tasks[i] - strength) != st.end()) {
                pills--;
                st.erase(st.lower_bound(tasks[i] - strength));
            } else return false;
        }
        
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        int st = 0;
        int end = min(tasks.size(), workers.size());
        int res = 0;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(possible(tasks, workers, pills, strength, mid)) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};