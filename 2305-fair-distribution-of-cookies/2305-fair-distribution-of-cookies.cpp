class Solution {
public:
    void calc(vector<int> &cookies, vector<int> &dist, int k, int i, int &mx){
        
        if(i==cookies.size()){
            int mxi = *max_element(dist.begin(),dist.end());
            mx = min(mx,mxi);
            return;
        }
        
        for(int j = 0; j < k; j++){
            dist[j] += (cookies[i]);
            calc(cookies,dist,k,i+1,mx);
            dist[j] -= cookies[i];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        
        vector<int> dist(k,0);
        
        calc(cookies,dist,k,0,ans);
        return ans;
    }
};