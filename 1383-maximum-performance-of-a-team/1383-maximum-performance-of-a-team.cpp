class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({speed[i],efficiency[i]});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> p1, pair<int,int> p2){
            return p1.second > p2.second;   
        });
        
        long  sum_speed = 0;
        long  ans = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            if(pq.size()==k) {
                sum_speed -= pq.top();
                pq.pop();
            }
            
            pq.push(v[i].first);
            sum_speed += v[i].first;
            long long t = (sum_speed*(long long)v[i].second);
            if(t > ans) {
                ans = t;
            }
        }
        
        return ans % (int)(1e9+7);
    }
};