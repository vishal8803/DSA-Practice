class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        ans[0] = {1};
        int count = 1;
        while(count < numRows) {
            ans[count] = vector<int>(count+1);
            ans[count][0] = 1;
            ans[count][count] = 1;
            for(int i = 1; i < count; i++){
                ans[count][i] = ans[count-1][i] + ans[count-1][i-1];
            }
            count++;
        }
        return ans;
    }
};