//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    int i = 0;
    int count = 0;
    while(i < n) {
        int j = i+1;
        while(j < n and price[j] >= price[j-1]) {
            j++;
        }
        j--;
        if(i < j and price[i] < price[j]) {
            count++;
            cout<<"("<<i<<" "<<j<<") ";
            i = j;
        } else {
            i++;
        }
        
    }
    if(count == 0) {
        cout<<"No Profit";
    }
    cout<<endl;
}

