//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> v;
void f() {
    int n = 100000;
	    vector<int> temp(n, 0);
	    v = temp;
          v[0] = v[1] = -1;
          for(int i = 2 ; i*i <= n ; i++){
              if(!v[i]){
                  for(int j = i*i ; j <= n ;j+=i){
                      v[j] = i;
                  }
              }
          }
}
static int i = 0;
class Solution {
	public:
	
	Solution() {
	    if(i == 0) {
	        f();
	        i++;
	    }
	}
    int Count(int L, int R){
        // Code here
        
        int prime = 0 , composite = 0 ;
        for(int i = L ; i <= R ; i++){
            if(v[i] > 0){
                composite++;
            }
            else if(v[i] == 0){
                prime++;
            }
        }
        return composite-prime;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends