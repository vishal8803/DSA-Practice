// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    vector<int> prime;
    
    Solution()
    {
        // Every index of prime stores zero or one
        // If prime[i] is zero means i is not a prime
        // If prime[i] is one means i is a prime
        prime.assign(10001,1);
        prime[0] = 0;
        prime[1] = 0;
        
        for(int i = 2; i * i <= 10000; i++){
            for(int j = 2*i; j<=10000; j+=i){
                prime[j] = 0;
            }
        }
        
    }
  
    int solve(int num1,int num2)
    {   
        queue<int> q;
        vector<int> visited(10000,-1);
        
        q.push(num1);
        visited[num1] = 0;
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            // cout<<n<<endl;
            string s = to_string(n);
            for(int i = 0; i < 4; i++){
                string temp = s;
                int start = (i==0?1:0);
                for(int j = start; j<=9; j++){
                    temp[i] = '0' + j;
                    int y = stoi(temp);
                    if(prime[y] && visited[y]==-1){
                        visited[y] = 1 + visited[n];
                        q.push(y);
                    }
                }
            }
        }
        return visited[num2];
    }
};


// { Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}  // } Driver Code Ends