class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int count = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int i = 0;
        int curr = 0;
        while(i < apples.size() or pq.size() > 0) {
            
            if(i < apples.size()) {
                if(apples[i] != 0)
                    pq.push({i + days[i], apples[i]});
                i++;
            }
            
            bool find  = false;
            while(pq.size() > 0) {
                auto it = pq.top();
                pq.pop();

                if(curr >= it.first) {continue;}
                if(it.second > 1)
                    pq.push({it.first, it.second-1});
                find = true;
                break;
            }
            if(find){
                count++;
            }
            
            curr++;
        }
        
        return count;
    }
};