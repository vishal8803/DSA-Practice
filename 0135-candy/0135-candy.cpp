class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int count = 2;
        vector<int> left(n), right(n);
        
        left[0] = 1;
        
        for(int i = 1; i < n; i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1] + 1;
            }else if(ratings[i]<=ratings[i-1]){
                left[i] = 1;
            }
        }
        
        right[n-1] = 1;
        count = 2;
        for(int i = n-2; i >= 0; i--){
            if(ratings[i]<=ratings[i+1]){
                right[i] = 1;
            }else if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            
            int mn = max(left[i],right[i]);
            sum += mn;
        }
        return sum;
    }
};