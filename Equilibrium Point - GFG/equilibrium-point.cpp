//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends



 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
    long long s =0 ;
        for(int i = 0 ; i<n ; i++)
        {
            s=s+a[i] ;
        }
        long long ls =0 ;
        for(int i =0 ; i<n ;i++)
        {
            s=s-a[i] ;
            if(ls==s)
            {
                return i+1 ;
            }else
            {
                ls=ls+a[i] ;
            }
        }
        return -1; 
    }

};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends