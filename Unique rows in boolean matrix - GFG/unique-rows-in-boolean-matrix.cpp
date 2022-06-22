// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/


vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    map<vector<int>, int> mp;
    vector<vector<int>> ans;
    
    for(int i = 0; i < row; i++){
        vector<int> temp;
        for(int j = 0; j < col; j++){
            temp.push_back(M[i][j]);
        }
        if(mp[temp] == 0){
            ans.push_back(temp);
        }
        mp[temp]++;
    }
    
    return ans;
}