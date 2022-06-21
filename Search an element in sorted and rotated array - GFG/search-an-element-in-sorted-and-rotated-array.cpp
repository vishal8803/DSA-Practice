// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int binary(vector<int> a ,int low ,int high ,int x)
{
    int st =low  ;
    int end =high ;
    while(st<=end)
    {
        int mid =(st+end)/2 ;
        if(a[mid]==x)return mid ;
        else if(a[mid]>x)
        {
            end =mid-1 ;
        }else{
            st=mid+1 ;
        }
    }
    return -1 ;
}

int Search(vector<int> vec, int K) {
    int st = 0;
    int end = vec.size()-1;
    
    while(st<end){
        int mid = (st) + (end-st)/2;
        if(vec[mid] < vec[end]){
            end = mid;
        }else{
            st = mid + 1;
        }
    }
    int t1 = binary(vec,0,st,K);
    if(t1 != -1){
        return t1;
    }
    
    return binary(vec,st+1,vec.size()-1,K);
}