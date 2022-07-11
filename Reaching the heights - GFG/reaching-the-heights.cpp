// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    sort(a,a+n);
    int j = n-1;
    int i = 0;
    
    
    
    vector<int> ans(n);
    
    while(j>=0 && i<n){
        ans[i] = a[j];
        j--;
        i+=2;
    }
    
    j = 0;
    i = 1;
    while(j<n && i<n){
        ans[i] = a[j];
        i+=2;
        j++;
    }
    
    int s = 0;
    
    for(int i = 0; i < n; i++){
        if(i%2==0){
            s += ans[i];
        }else{
            s -= ans[i];
        }
    }
    if(s==0){
        return {-1};
    }
    return ans;
}
