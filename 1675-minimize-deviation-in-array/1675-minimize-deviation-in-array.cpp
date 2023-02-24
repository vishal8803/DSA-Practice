class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int,vector<int>> pq;
        int mn = INT_MAX;
        for(int i : nums){
            if(i%2)
                i=i*2;
            pq.push(i);
            mn = min(mn,i);
        }
        int diff = INT_MAX;
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            diff = min(diff, t-mn);
            if(t%2)
                break;
            mn=min(mn,t/2);
            pq.push(t/2);
        }
        return diff;
    }
};