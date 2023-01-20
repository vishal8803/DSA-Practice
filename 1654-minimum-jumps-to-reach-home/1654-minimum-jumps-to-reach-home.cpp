class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> st;
        for(int i : forbidden) {
            st.insert(i);
        }
        
        queue<pair<int,int>> q;
        set<pair<int,int>> visited;
        
        q.push({x, -1});
        int count = 0;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int prev = it.second;
                if(node == 0) return count;
                
                if(prev == 0 or prev == -1) {
                    if(node - a >= 0) {
                        int val = node - a;
                        if(visited.find({val, prev}) == visited.end() and st.find(val) == st.end()) {
                            visited.insert({val, prev});
                            q.push({val, prev});
                        }
                    }
                    
                    if(st.find(node + b) == st.end() and visited.find({node+b, 1}) == visited.end() and node + b <= 10000){
                        q.push({node + b, 1});
                        visited.insert({node + b, 1});
                    }
                    
                } else {
                    if(node - a >= 0) {
                        int val = node - a;
                        if(visited.find({val, 0}) == visited.end() and st.find(val) == st.end()) {
                            visited.insert({val, 0});
                            q.push({val, 0});
                        }
                    }
                }
            }
            count++;
        }
        
        return -1;
    }
};