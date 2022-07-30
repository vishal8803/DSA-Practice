class Solution {
public:
    bool isTurbulent(vector<int> &arr, int k) {
        return ((arr[k] > arr[k-1] && arr[k] > arr[k+1]) || (arr[k] < arr[k-1] && arr[k] < arr[k+1]));
    }
    
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() < 2) return arr.size();
        
        int mx = 1;
        int start = 0;
        int end = 0;
        int len = arr.size();
        
        while(start+1 < len) {
            if(arr[start]==arr[start+1])
            {
                start++;
                continue;
            }
            end = start + 1;
            while(end+1 < len && isTurbulent(arr, end)){
                end++;
            }
            mx = max(mx,end-start+1);
            start = end;
        }
        
        return mx;
    }
};