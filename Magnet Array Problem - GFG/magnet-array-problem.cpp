// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void nullPoints(int n, double magnets[], double getAnswer[])
    {
        for(int i = 0; i < n - 1; i++){
            double st = magnets[i];
            double end = magnets[i+1];
            bool flag = false;
            while(st<end){
                double mid = (st+end)/2; 
                
                double totalForce = 0;
                
                for(int j = 0; j < n; j++){
                    totalForce += (1/(mid-magnets[j]));
                }
               
                if(abs(totalForce)<0.000001){
                    getAnswer[i] = mid;
                    flag = true;
                    break;
                }else if(totalForce < 0){
                    end = mid;
                }else{
                    st = mid;
                }
            }
            if(!flag)
                getAnswer[i] = st;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends