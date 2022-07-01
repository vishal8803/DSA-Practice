// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int MOD = 1000000007;
    vector<vector<long long int>> multiply(vector<vector<long long int>> &v1, vector<vector<long long int>> &v2){
        int n = v1.size();
        vector<vector<long long int>> ans(n, vector<long long int>(n,0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    ans[i][j] = (ans[i][j]%MOD +  v1[i][k] * v2[k][j])%MOD;
                }
            }
        }
        
        return ans;
    }
    vector<vector<long long int>> matrixExponentitate(vector<vector<long long int>> &v, long long int n){
        if(n==0){
            int sz = v.size();
            vector<vector<long long int>> ans(sz, vector<long long int>(sz,0));
            for(int i = 0; i < sz; i++){
                ans[i][i] = 1;
            }
            return ans;
        }
        
        vector<vector<long long int>> temp = matrixExponentitate(v,n/2);
        vector<vector<long long int>> ans = multiply(temp,temp);
        
        if(n&1){
            ans = multiply(ans,v);
        }
        
        return ans;
    }
    int FindNthTerm(long long int n) {
        vector<vector<long long int>> v = {{1,1},{1,0}};
        vector<vector<long long int>> ans = matrixExponentitate(v,n);
        return ans[0][0];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends