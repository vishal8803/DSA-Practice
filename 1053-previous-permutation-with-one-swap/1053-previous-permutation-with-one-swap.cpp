class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr;
        else if(n == 2) {
            if(arr[0] > arr[1]) swap(arr[0], arr[1]);
            return arr;
        }
        
        int idx = -1;
        for(int i = n - 1; i >= 1; i--) {
            if(arr[i-1] > arr[i]) {
                idx = i - 1;
                break;
            }
        }
        
        if(idx == -1) return arr;
        
        int idx2 = idx+1;
        for(int i = idx + 1; i < n; i++) {
            if(arr[i] < arr[idx] and arr[i] > arr[idx2]) {
                idx2 = i;
            }
        }
        
        swap(arr[idx], arr[idx2]);
        return arr;
    }
};