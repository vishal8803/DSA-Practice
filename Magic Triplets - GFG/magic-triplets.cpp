// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int countTriplets(vector<int>nums){
	    vector<int> left;
	    vector<int> right;
	    
	    for(int i = 0; i < nums.size(); i++){
	        
	        int count1 = 0;
	        int count2 = 0;
	        for(int j = 0; j < i; j++){
	            if(nums[j] < nums[i]){
	                count1++;
	            }
	        }
	        
	        for(int j = i + 1; j < nums.size(); j++){
	            if(nums[j] > nums[i]){
	                count2++;
	            }
	        }
	        
	        left.push_back(count1);
	        right.push_back(count2);
	    }
	    
	    int ans = 0;
	    for(int i = 0; i < nums.size(); i++){
	        ans += left[i] * right[i];
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends