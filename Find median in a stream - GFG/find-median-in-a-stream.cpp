// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue<int, vector<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(pq1.empty() || pq1.top() > x){
            pq1.push(x);
        }else{
            pq2.push(x);
        }
        if(pq1.size()>1+pq2.size()){
            pq2.push(pq1.top());
            pq1.pop();
        }else if(pq2.size()>1+pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        
        if(pq1.size()>pq2.size())
        {
            return pq1.top() ;
        }else if(pq1.size()<pq2.size())
        {
            return pq2.top() ;
        }else{
            return (pq1.top() + pq2.top())/2.0 ;
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends