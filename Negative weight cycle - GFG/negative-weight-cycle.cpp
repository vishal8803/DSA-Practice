// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n,INT_MAX);
	    
	    dist[0] = 1;
	    
	    for(int i = 0; i < n; i++){
	        for(vector<int> edge : edges){
	            if(dist[edge[0]]==INT_MAX)
	                continue;
	                
	            if(dist[edge[0]] + edge[2] < dist[edge[1]]){
	                dist[edge[1]] = dist[edge[0]] + edge[2];
	            }
	        }
	    }
	    
	    for(vector<int> edge : edges){
            if(dist[edge[0]]==INT_MAX)
                continue;
                
            if(dist[edge[0]] + edge[2] < dist[edge[1]]){
                return true;
            }
        }
	    
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends