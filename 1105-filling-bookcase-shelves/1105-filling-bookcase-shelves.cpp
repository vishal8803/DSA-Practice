class Solution {
public:
    int dp[1001][1001];
    int calc(vector<vector<int>> &books, int width, int i) {
        if(i == books.size()) return 0;
        
        if(dp[width][i] != -1) return dp[width][i];
        
        int mx = 0;
        int temp = width;
        int j = i;
        int res = INT_MAX;
        
        while(i < books.size() and width >= books[i][0]) {
            mx = max(mx, books[i][1]);
            width -= books[i][0];
            res = min(res, mx + calc(books, temp, i + 1));
            i++;
        }
        
        return dp[temp][j] = res;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        return calc(books, shelfWidth, 0);
    }
};