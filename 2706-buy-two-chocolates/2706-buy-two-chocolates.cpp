class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices), end(prices));
        int t1 = prices[0];
        int t2 = prices[1];
        if(money - t1 - t2 >= 0) return money - t1 - t2;
        return money;
    }
};