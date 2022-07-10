class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int j = 0; j < m; j++){
            int k = j;
            vector<int> temp;
            
            for(int i=0; i<n && k>=0 ; i++, k--){
                temp.push_back(mat[i][k]);
            }
            
            ans.push_back(temp);
        }
        
        for(int i = 1; i < n; i++){
            int k = i;
            vector<int> temp;
            
            for(int j = m-1; j>=0 && k<n; j--, k++){
                temp.push_back(mat[k][j]);
            }
            ans.push_back(temp);
        }
        
        vector<int> finalAns;
        bool flag = true;
        
        for(vector<int> t : ans){
            if(flag){
                reverse(t.begin(),t.end());
            }
            for(int i : t){
                finalAns.push_back(i);
            }
            flag = !flag;
        }
        
        return finalAns;
    }
};