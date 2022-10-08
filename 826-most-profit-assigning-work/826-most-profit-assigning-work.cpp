class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
         if(*max_element(worker.begin(), worker.end()) < *min_element(difficulty.begin(), difficulty.end())) 
             return 0;
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i < profit.size(); i++) {
            v.push_back({difficulty[i], profit[i]});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> &p1, pair<int,int> &p2) {
            return p1.first < p2.first;
        });
        
        int sum = 0;
        int n = profit.size();
        
        vector<int> prefix(n, 0);
        prefix[0] = v[0].second;
        
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i-1], v[i].second);
        }
        
        for(int i = 0; i < worker.size(); i++) {
            int diff = worker[i];
            
            int st = 0;
            int end = n - 1;
            int res = -1;
            
            while(st <= end) {
                int mid = (st + end)/2;
                if(v[mid].first > diff) {
                    end = mid - 1;
                } else {
                    res = mid;
                    st = mid + 1;
                }
            }
            if(res != -1)
            sum += prefix[res];
        }
        
        return sum;
    }
};