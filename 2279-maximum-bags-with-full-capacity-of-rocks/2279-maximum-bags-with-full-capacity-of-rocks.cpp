class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int count = 0;
        for(int i = 0; i < rocks.size(); i++){
            if(rocks[i]==capacity[i]){
                count++;
                continue;
            }
            else{
                pq.push(capacity[i]-rocks[i]);
            }
        }
        
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            if(t<=ar){
                count++;
                ar-=t;
            }else{
                break;
            }
        }
        return count;
    }
};