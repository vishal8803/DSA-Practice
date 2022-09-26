class Solution {
public:
    int parent[100000];
    
    void makeset(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int n) {
        if(n == parent[n]) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        makeset(n);
        map<int,int> count;
        map<int,int> maxVal;
        makeset(n);
        
        for(int i = 0; i < n; i++) {
            maxVal[i] = vals[i];
            count[i] = 1;
        }
        
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
            int f1 = max(vals[a[0]], vals[a[1]]);
            int f2 = max(vals[b[0]], vals[b[1]]);
            
            return f1 < f2;
        });
        
        int cnt = n;
        
        for(auto edge : edges) {
            int a = findParent(edge[0]);
            int b = findParent(edge[1]);
            
            if(maxVal[a]==maxVal[b]) {
                cnt += count[a] * count[b];
                count[b] += count[a];
                parent[a] = b;
            } else {
                if(maxVal[a] > maxVal[b]) {
                    parent[b] = a;
                } else {
                    parent[a] = b;
                }
            }
        }
        
        return cnt;
    }
};