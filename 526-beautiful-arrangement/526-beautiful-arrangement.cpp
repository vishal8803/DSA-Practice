class Solution {
public:
    void calc(int n, int &count, vector<bool> &visited, int idx){
        if(idx==n){
            count++;
            return;
        }
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                if(i%(idx+1)==0 || (idx+1)%i==0){
                    visited[i] = true;
                    calc(n,count,visited,idx+1);
                    visited[i] = false;
                }
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n+1);
        int count = 0;
        calc(n,count,visited,0);
        return count;
    }
};