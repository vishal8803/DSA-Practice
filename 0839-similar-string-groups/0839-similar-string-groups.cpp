class DisjointSet {
    public:
        vector<int> parent, rank;

        DisjointSet(int n) {
            parent.resize(n, 0);
            rank.resize(n, 0);

            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if(node == parent[node]) return node;

            return parent[node] = findParent(parent[node]);
        }

        void makeUnion(int node1, int node2) {
            node1 = findParent(node1);
            node2 = findParent(node2);

            if(rank[node1] > rank[node2]) {
                parent[node2] = node1;
            } else if(rank[node2] > rank[node1]) {
                parent[node1] = node2;
            } else {
                parent[node1] = node2;
                rank[node2]++;
            }
        }
};

class Solution {
private:
    bool isSimilar(string s1, string s2) {
        int diff = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) diff++;
        }
        
        return diff <= 2;
    }
    
public:
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    ds.makeUnion(i, j);
                }
            }
        }
        
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(ds.findParent(i));
        }
        return st.size();
    }
};