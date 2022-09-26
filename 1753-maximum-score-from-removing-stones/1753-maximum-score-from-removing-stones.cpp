class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int ans = 0;
        
        while(true) {
            int t1 = pq.top();
            pq.pop();
            
            int t2 = pq.top();
            pq.pop();
            
            if(t1 > 0 && t2 > 0) {
                pq.push(t1 - 1);
                pq.push(t2 - 1);
                ans++;
            } else break;
        }
        
        return ans;
    }
};