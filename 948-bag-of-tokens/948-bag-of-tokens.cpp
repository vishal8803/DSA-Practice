class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0;
        int j = tokens.size()-1;
        int score = 0;
        int ans = 0;
        
        sort(tokens.begin(), tokens.end());
        
        while(i<=j) {
            if(power >= tokens[i]) {
                power -= tokens[i++];
                score++;
                ans = max(ans, score);
            } else if(score > 0) {
                score--;
                power+= tokens[j--];
            } else break;
        }
        
        return ans;
    }
};