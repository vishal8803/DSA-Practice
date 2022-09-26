class Solution {
public:
    int parent[26];
    int rnk[26];
    
    void makeset() {
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
            rnk[i] = 0;
        }
    }
    
    int findParent(int node) {
        if(node == parent[node]) return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void makeUnion(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        if(rnk[u] > rnk[v]) {
            parent[v] = u;
        } else if(rnk[v] > rnk[u]) {
            parent[u] = v;
        } else {
            parent[u] = v;
            rnk[v]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        makeset();
        
        for(string eq : equations) {
            char ch1 = eq[0];
            char ch2 = eq[3];
            
            if(eq[1]=='=') {
                if(findParent(ch1-'a') != findParent(ch2 - 'a')) makeUnion(ch1-'a', ch2-'a');
            } 
        }
        
        for(string eq : equations) {
            char ch1 = eq[0];
            char ch2 = eq[3];
            
            if(eq[1]=='!') {
                if(findParent(ch1-'a') == findParent(ch2 - 'a')) return false;
            } 
        }
        
        return true;
    }
};