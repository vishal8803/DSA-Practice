class Solution {
public:
    static const int N = 1e5 + 5;
    
    int freq[N];
    int par[N], rnk[N];
    
    Solution() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            freq[i] = 0;
            rnk[i] = 1;
        }
    }
    
    int findParent(int n) {
        if(par[n] == n) return n;
        
        return par[n] = findParent(par[n]);
    }
    
    void merge(int u, int v) {
        int a = findParent(u);
        int b = findParent(v);
        
        if(a != b){
            freq[rnk[a]]--;
            freq[rnk[b]]--;

            par[a] = b;
            rnk[b] += rnk[a];
            freq[rnk[b]]++;
        }
        
    }
    
    int findLatestStep(vector<int>& arr, int m) {
        int step = -1;
        int n = arr.size();
        vector<int> c(n+2,0);
        int cnt = 1;
        for(int i : arr) {
            c[i] = 1;
            freq[1]++;
            if(c[i-1]) merge(i,i-1);
            if(c[i+1]) merge(i,i+1);
            if(freq[m]) step = cnt;
            cnt++;
        }
        return step;
    }
};