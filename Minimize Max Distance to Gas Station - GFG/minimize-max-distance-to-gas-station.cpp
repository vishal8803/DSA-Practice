//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
      int n = stations.size();
      double st = 0;
      double end = stations[n-1] - stations[0];
      
      
      auto isPossible = [&](double distance) {
          int count = 0;
          for(int i = 0; i < n - 1; i++) {
              count += ((double)(stations[i+1] - stations[i])/(distance));
          }
          return count <= K;
      };
      
      while(end - st > 1e-6) {
          double mid = st + (end -st)/2.0;
          if(isPossible(mid)) {
              end = mid;
          } else {
              st = mid;
          }
      }
      
      return end;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends