class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double, vector<double>> pq;
        int count = 0;
        double sum = 0;
        double initial = 0;
        
        for(int i : nums) {
            sum += (double)i;
            pq.push((double)i);
        }
        
        initial = sum;
        
        while(true) {
            double num = pq.top();
            pq.pop();
            
            sum -= num/2.0;
            count++;
            pq.push(num/2.0);
            
            if(initial/2.0 >= sum) break;
        }
        
        return count;
    }
};