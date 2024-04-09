class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }
        
        int seconds = 0;
        
        while(q.size() > 0) {
            auto it = q.front();
            q.pop();
            it.first--;
            if(it.first == 0) {
                if(it.second == k) return seconds+1;
            } else {
                q.push(it);
            }
            seconds++;
        }
        
        return seconds;
    }
};