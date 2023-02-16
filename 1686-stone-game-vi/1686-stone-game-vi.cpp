class Compare {
public:
    bool operator()(pair<int,int> p1, pair<int,int> p2)
    {
        return p1.first + p1.second < p2.first + p2.second;
    }
};

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int ascore = 0;
        int bscore = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(int i = 0; i < aliceValues.size(); i++) {
            pq.push({aliceValues[i] , bobValues[i]});
        }
        
        while(pq.size() > 0) {
            ascore += pq.top().first;
            pq.pop();
            
            if(pq.size() > 0) {
                bscore += pq.top().second;
                pq.pop();
            }
        }
        
        if(ascore > bscore) return 1;
        else if(ascore == bscore) return 0;
        return -1;
    }
};