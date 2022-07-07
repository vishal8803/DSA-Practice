class Solution {
public:
    void solve(vector<int> &v, int idx, int k, int &ans){
        if(v.size()==1){
            ans = v[0];
            return;
        }
        idx = (idx + k)%v.size();
        v.erase(v.begin()+idx);
        solve(v,idx,k,ans);
    }
    int findTheWinner(int n, int k) {
        vector<int> a(n,0);
        for(int i = 0; i<n; i++){
            a[i] = i+1;
        }
        int ans;
        k--;
        solve(a,0,k,ans);
        return ans;
    }
};