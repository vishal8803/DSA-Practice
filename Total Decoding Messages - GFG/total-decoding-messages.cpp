//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    long long dp[str.length()];
		    dp[0]=1;
		    int lz =0 ;
		    for(int i=0; i<str.length(); i++)
		    {
		        if(str[i]=='0')
		            return 0;
		           else
		            break;
		    }
		  
		  int MOD = 1000000007 ;
		    for(int i=1; i<str.length(); i++){
		        if(str[i-1]=='0' && str[i]=='0')
		        {
		            dp[i]=0;
		        }else if(str[i-1]=='0' && str[i]!='0'){
		            dp[i]=dp[i-1]%MOD;
		        }else if(str[i-1]!='0' && str[i]=='0'){
		            if(str[i-1]=='1' || str[i-1]=='2')
		            {
		              //  int x = dp[i-1];
		                int y = (i>=2? dp[i-2]:1);
		                dp[i]=( y%MOD);
		            }else
		            {
		                dp[i]=0;
		            }
		        }else{
		             string temp = str.substr(i-1,2);
		            int y = stoi(temp);
		            if(y<=26){
		                int x = dp[i-1];
		                int e = (i>=2? dp[i-2]:1);
		                dp[i]=(x%MOD + e%MOD)%MOD;
		            }else
		            {
		                dp[i]=dp[i-1]%MOD;
		            }
		        }
		        
		    }
		    return dp[str.length()-1]%MOD;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends