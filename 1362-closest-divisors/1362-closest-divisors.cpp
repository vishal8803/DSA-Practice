class Solution {
public:
    vector<int> ans;
    int diff = INT_MAX;
    void minDiff(int num) {
        

        for(int i = 1; i*i <= num; i++) {
            if(num%i == 0) {
                int r = num/i;
                if(abs(i - r) < diff) {
                    diff = abs(i - r);
                    vector<int> temp = {i,r};
                    ans = temp;
                }
            }
        }
    }

    vector<int> closestDivisors(int num) {
        minDiff(num + 1);
        minDiff(num + 2);
        return ans; 
    }
};