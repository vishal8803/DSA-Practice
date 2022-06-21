// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int mx = 0;
            int rowNum = 0;
            
            for(int i = 0; i < N; i++){
                vector<int> temp = Mat[i];
                int st = 0;
                int end = temp.size()-1;
                
                while(st<=end){
                    int mid = (st+end)/2;
                    
                    if(temp[mid]==0){
                        st = mid + 1;
                    }else if(temp[mid]==1){
                        int t = temp.size();
                        if(t-mid > mx){
                            mx = t-mid;
                            rowNum = i;
                        }
                        end = mid - 1;
                    }
                }
            }
            return rowNum;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends