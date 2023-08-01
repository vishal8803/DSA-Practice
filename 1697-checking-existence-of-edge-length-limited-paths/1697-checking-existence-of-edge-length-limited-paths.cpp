class Solution {
public:
    int parent[100001];
    int rnk[100001];
    
    void makeset(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rnk[i] = 0;
        }
    }
    
    int findParent(int node) {
        if(node == parent[node]) return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void makeUnion(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);
        if(node1 == node2) return;
        
        if(rnk[node1] > rnk[node2]) {
            parent[node2] = node1;
        } else if(rnk[node2] > rnk[node1]) {
            parent[node1] = node2;
        } else {
            parent[node1] = node2;
            rnk[node2]++;
        }
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        map<vector<int>, vector<int>> mp;
        int q = queries.size();
        vector<bool> ans(q, 0);
        
        for(int i = 0; i < queries.size(); i++) {
            mp[queries[i]].push_back(i);
        }
        
        sort(begin(queries), end(queries), [&](vector<int> &v1, vector<int> &v2) {
            return v1[2] < v2[2];
        });
        
        sort(begin(edgeList), end(edgeList), [&](vector<int> &v1, vector<int> &v2) {
            return v1[2] < v2[2];
        });
        
        makeset(n);
        int i = 0;
        int j = 0;
        
        while(j < q) {
            int x = queries[j][0];
            int y = queries[j][1];
            int limit = queries[j][2];
            
            
            while(i < edgeList.size() and edgeList[i][2] < limit) {
                int u = edgeList[i][0];
                int v = edgeList[i][1];
                i++;
                makeUnion(u, v);
            }
            
            if(findParent(x) == findParent(y)) {
                vector<int> temp = mp[queries[j]];
                for(int g : temp) ans[g] = 1;
            } else {
                vector<int> temp = mp[queries[j]];
                for(int g : temp) ans[g] = 0;
            }
            j++;
        }
        
        return ans;
    }
};