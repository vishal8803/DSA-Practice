class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return arr[0];
        
        int res = arr[0];
        int prenot = arr[0];
        int pre = 0;
        
        for(int i = 1; i < n; i++) {
            pre = max(prenot, pre + arr[i]);
            prenot = max(arr[i], prenot + arr[i]);
            res = max(res, max(pre, prenot));
        }
        
        return res;
    }
};