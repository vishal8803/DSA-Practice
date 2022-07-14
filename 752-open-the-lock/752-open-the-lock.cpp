class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> visit(10000,0);
        for(string s : deadends) visit[stoi(s)] = 1;
        
        if(visit[0]==1 || visit[stoi(target)]==1) return -1;
        
        queue<string> q;
        q.push("0000");
        visit[0] = 1;
        
        int cnt = 0;
        while(q.size()>0){
            int size = q.size();
            while(size--){
                string t = q.front();
                q.pop();
                if(t==target)
                    return cnt;
                
                for(int i = 0; i < 4; i++){
                    int y = t[i]-'0';
                    int z = (y+1)%10;
                    t[i] = z + '0';
                    if(visit[stoi(t)] != 1){
                        q.push(t);
                        visit[stoi(t)] = 1;
                    }
                    z = (10+y-1)%10;
                    t[i] = z + '0';
                    if(visit[stoi(t)]!= 1){
                        q.push(t);
                        visit[stoi(t)] = 1;
                    }
                    t[i] = y + '0';
                }
            }
            cnt++;
        }
        return -1;
    }
};