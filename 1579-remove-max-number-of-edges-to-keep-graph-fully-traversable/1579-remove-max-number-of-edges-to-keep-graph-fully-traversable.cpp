class DSU
{
    int components;
    vector<int> parent, rnk;

    public:

    DSU(int n) {
        components = n;
        parent.push_back(0);
        rnk.push_back(0);
        for(int i = 1; i<= n; i++) {
            parent.push_back(i);
            rnk.push_back(1);
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    int makeUnion(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if(u == v) return 0;

        if(rnk[u] > rnk[v]) {
            rnk[u] += rnk[v];
            parent[v] = u;
        } else if(rnk[v] > rnk[u]) {
            rnk[v] += rnk[u];
            parent[u] = v;
        } else {
            parent[v] = u;
            rnk[u] += rnk[v];
        }

        components--;
        return 1;
    }

    bool isConnected() {
        return components == 1;
    }

};

class Solution {
public:
    
    int twoFourWheelRoads(vector<vector<int> > &edges, int n, int m){
        DSU TwoWheeler(n), FourWheeler(n);
        int cnt = 0;
        for(auto &edge : edges) {
            if(edge[0] == 3) {
                cnt += (TwoWheeler.makeUnion(edge[1], edge[2]) | FourWheeler.makeUnion(edge[1], edge[2]));
            }
        }

        for(auto &edge : edges) {
            if(edge[0] == 1) {
                cnt += TwoWheeler.makeUnion(edge[1], edge[2]);
            } else if(edge[0] == 2) {
                cnt += FourWheeler.makeUnion(edge[1], edge[2]);
            }
        }

        if(TwoWheeler.isConnected() and FourWheeler.isConnected()) {
            return m - cnt;
        }

        return -1;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        return twoFourWheelRoads(edges, n, edges.size());
    }
};