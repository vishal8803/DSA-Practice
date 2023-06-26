class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int i = 0;
        while(i < candidates) {
            pq1.push(costs[i++]);
        }
        int j = costs.size() - 1;
        while(costs.size() - j <= candidates and j >= candidates) {
            pq2.push(costs[j--]);
        }
        
        long long cost = 0;
        while(k--) {
            if(pq1.size() != 0 and pq2.size() != 0){
            if(pq1.top() <= pq2.top()) {
                cost += pq1.top();
                // cout<<pq1.top()<<endl;
                pq1.pop();
                if(i <= j) {
                    pq1.push(costs[i++]);
                }
            } else if(pq1.top() > pq2.top()) {
                cost += pq2.top();
                // cout<<pq2.top()<<endl;
                pq2.pop();
                if(i <= j) {
                    pq2.push(costs[j--]);
                }
            }
            } else if(pq1.size() != 0) {
                cost += pq1.top();
                // cout<<pq1.top()<<endl;
                pq1.pop();
                if(i <= j) {
                    pq1.push(costs[i++]);
                }
            } else {
                cost += pq2.top();
                // cout<<pq1.top()<<endl;
                pq2.pop();
                if(i <= j) {
                    pq2.push(costs[j--]);
                }
            }
        }
         return cost;
    }
};