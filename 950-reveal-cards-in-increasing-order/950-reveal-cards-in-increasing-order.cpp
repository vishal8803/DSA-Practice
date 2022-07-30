class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size());
        queue<int> q;
        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }
        int i = 0;
        
        while(i<deck.size()) {
            int t = q.front();
            q.pop();
            ans[t] = deck[i];
            i++;
            if(q.size()>0){
                int t2 = q.front();
                q.pop();
                q.push(t2);
            }
        }
        return ans;
    }
};