//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	     int osc =0 ;
           int esc =0 ;
           int count=1 ;
           for(int i = s.length()-1 ; i>=0 ; i--){
               if(count%2==1){
                   if(s[i]=='1'){
                       osc++ ;
                   }
               }else{
                   if(s[i]=='1'){
                       esc++ ;
                   }
               }
               count++ ;
           }
           if(abs(esc-osc)%3==0){
               return 1 ;
           }else{
               return 0 ;
           }
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends