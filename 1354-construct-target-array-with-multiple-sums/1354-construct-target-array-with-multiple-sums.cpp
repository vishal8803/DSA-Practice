class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long,vector<long long>> pq;
        
        for(int i : target){
            sum += i;
            pq.push((long long)i);
        }
        
        while(pq.top() != 1){
            long long top = pq.top();
            pq.pop();
            sum = sum - top;
            if(sum <= 0 || sum >= top)
                return false;
            
            top = top%sum;
            sum = sum + top;
            pq.push(top!=0?top:sum);
        }
        
        return true;
    }
};