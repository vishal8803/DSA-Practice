class Solution {
    vector<int> parent;
    vector<int> rnk;
public:
    void makeset(int n){
        parent = vector<int>(n);
        rnk = vector<int>(n);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i <n; i++)
            rnk[i] = 0;
    }
    
    int find(int n){
        if(parent[n]==n){
            return n;
        }
        
        return parent[n] = find(parent[n]);
    }
    
    void makeUnion(int u, int v){
        u = find(u);
        v = find(v);
        
        if(rnk[u] > rnk[v]){
            parent[v] = u;
        }else if(rnk[v] > rnk[u]){
            parent[u] = v;
        }else{
            parent[v] = u;
            rnk[u]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        makeset(20005);
        for(vector<int> stone : stones){
            makeUnion(stone[0],stone[1]+10001);
        }
        set<int> st;
        for(vector<int> stone : stones){
            st.insert(find(stone[0]));
        }
        
        return stones.size()-st.size();
    }
};