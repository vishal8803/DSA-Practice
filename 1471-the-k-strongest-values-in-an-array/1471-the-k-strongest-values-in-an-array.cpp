class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[(n-1)/2];
        
        int i = 0;
        int j = arr.size() - 1;
        vector<int> ans;
        
        while(k > 0) {
            if(abs(median - arr[i]) > abs(median - arr[j])) {
                ans.push_back(arr[i++]);
            } else if(abs(median - arr[i]) < abs(median - arr[j])) {
                ans.push_back(arr[j--]);
            } else {
                if(arr[i] > arr[j]) {
                    ans.push_back(arr[i++]);
                } else {
                    ans.push_back(arr[j--]);
                }
            }
            k--;
        }
        
        return ans;
    }
};