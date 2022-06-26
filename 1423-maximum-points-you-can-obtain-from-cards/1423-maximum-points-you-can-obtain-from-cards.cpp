class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        ans = max(ans,sum);
        // cout<<sum<<endl;
        for(int i = k-1, j = cardPoints.size()-1; i>=0 ; i--,j--){
            sum = sum - cardPoints[i] + cardPoints[j];
            // cout<<sum<<endl;
            ans = max(ans,sum);
        }
        return ans;
    }
};