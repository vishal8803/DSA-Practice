class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        
        while(i < n - 1 and arr[i] <= arr[i+1])i++;
        if(i == n - 1) return 0;
        
        while(j >= i and arr[j] >= arr[j-1])j--;
        if(j == 0) return n - 1;
        
        int k = 0, l = j;
        int res = min(n - i - 1, j);
        
        while(k <= i and l < n) {
            if(arr[k] <= arr[l]) {
                res = min(res, l - k -1);
                k++;
            } else {
                l++;
            }
        }
        
        return res;
    }
};