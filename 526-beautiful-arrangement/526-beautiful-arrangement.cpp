class Solution {
public:
    void calc(int n, vector<bool> &visited, int &count, int idx) {
        if(idx==n) {
            count++;
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                if(i%(idx+1)==0 || (idx+1)%i==0){
                    visited[i] = true;
                    calc(n,visited,count,idx+1);
                    visited[i] = false;
                }
            }
        }
    }
    
    int countArrangement(int n) {
        int count = 0;
        vector<bool> visited(n+1,false);
        calc(n,visited,count,0);
        return count;
    }
};