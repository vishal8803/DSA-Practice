class Solution {
public:
    int get(vector<int> &a, int tar) {
        int st = 0;
        int end = a.size() - 1;
        int res = -1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(a[mid] > tar) {
                end = mid - 1;
            } else {
                res = mid;
                st = mid + 1;
            }
        }
        
        return res;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        int n = items.size();
        
        sort(items.begin(), items.end());
        
        vector<int> price(n), beauty(n);
        
        for(int i = 0; i < n; i++) {
            price[i] = items[i][0];
            beauty[i] = items[i][1];
        }
        
        for(int i = 1; i < n; i++) {
            beauty[i] = max(beauty[i], beauty[i-1]);
        }
        
        for(int q : queries) {
            int idx = get(price, q);
            
            if(idx==-1) ans.push_back(0);
            else ans.push_back(beauty[idx]);
        }
        
        return ans;
    }
};