class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        for(int i =0; i < mat.size(); i++){
            int count = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            ans.push_back(count);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < ans.size(); i++){
            pq.push({ans[i],i});
        }
        
        vector<int> r;
        while(r.size()<k){
            r.push_back(pq.top().second);
            pq.pop();
        }
        return r;
    }
};