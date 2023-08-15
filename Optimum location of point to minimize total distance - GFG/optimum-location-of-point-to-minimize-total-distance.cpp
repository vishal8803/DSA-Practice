//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define sq(x) ((x) * (x))
class Solution{
    public:
    
    double calc(int a, int b, int c, vector<vector<int>> &points, double x, int n) {
    	double y = (-1.0*(a*x + c))/b;
    	double res = 0;
    
    	for(auto point : points) {
    		res += sqrt(sq(point[0] - x) + sq(point[1] - y));
    	}
    
    	return res;
    } 
    
    double optimumDistance(int a, int b, int c, vector<vector<int>> &points, int n){
    	double low = -1e6;
    	double high = 1e6;
    
    	double eps = 1e-6;
    
    	while(high - low > eps) {
    		double mid1 = low + (high - low)/3.0;
    		double mid2 = high - (high - low)/3.0;
    
    		double d1 = calc(a, b, c, points, mid1, n);
    		double d2 = calc(a, b, c, points, mid2, n);
    
    		if(d1 < d2) {
    			high = mid2;
    		} else low = mid1;
    	}
    
    	return calc(a,b,c,points, (high+low)/2, n);
    }
    
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    vector<vector<int>> points;
	    for(int i = 0; i < n; i++) {
	        points.push_back({p[i].first, p[i].second});
	    }
	    return optimumDistance(get<0>(l), get<1>(l), get<2>(l), points, n);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends