//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countMoves(int a,int b,int &lgt,int& brt){

        if(a<b) swap(a,b);

        if(a<=lgt && b<=brt) return 0;

        //if length doesnot fits

        if(a>lgt)

        return 1 + countMoves(a/2,b,lgt,brt);

        //if breadth doesnot fit

        return 1+ countMoves(a,b/2,lgt,brt);

    }

    int carpetBox(int A, int B, int C, int D){

        //code here

        if(C<D) swap(C,D);

        return countMoves(A,B,C,D);

    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends