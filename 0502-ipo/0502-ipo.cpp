class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        
        int n = profits.size();
        
        for(int i = 0; i < n; i++) {
            v.push_back({capital[i], profits[i]});
        }
        
        sort(v.begin(), v.end());
        
        int i = 0;
        priority_queue<int, vector<int>> pq;
        for(int j = 0; j < k; j++) {
            while(i < n and v[i].first <= w) {
                pq.push(v[i++].second);
            }
            if(pq.size() == 0) break;
            
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};