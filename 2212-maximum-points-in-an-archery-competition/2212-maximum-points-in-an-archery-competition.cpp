class Solution {
public:
    void calc(vector<int> &aliceArrows, int n, vector<int> &res, vector<int> &temp, int &score, int currScore, int i) {
        
        if(n <= 0 || i < 0) {
            // cout<<currScore<<endl;
            if(score < currScore) {
                res = temp;
                score = currScore;
            }
            return;
        }
        
        
        if(aliceArrows[i] + 1 <= n) {
            temp[i] = aliceArrows[i] + 1;
            calc(aliceArrows, n - aliceArrows[i] - 1, res, temp, score, currScore + i, i - 1);
            temp[i] = 0;
            calc(aliceArrows, n, res, temp, score, currScore, i - 1);
        } else {
            calc(aliceArrows, n, res, temp, score, currScore, i - 1);
        }
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12,0);
        int score = 0;
        vector<int> temp(12,0);
        calc(aliceArrows, numArrows, res, temp, score, 0, 11);
        int sum = 0;
        for(int i = 0; i < 12; i++) {
            sum += res[i];
        }
        res[0] += numArrows - sum;
        return res;
    }
};