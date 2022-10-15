class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int cols = s.size()/rows;
        
        vector<vector<char>> mat(rows,vector<char>(cols));
        int k = 0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = s[k++];
            }
        }
        
        string ans = "";
        
        for(int g = 0; g < cols; g++) {
            for(int i = 0, j = g; j < cols and i < rows; j++,i++) {
                ans += mat[i][j];
            }
        }
        int idx = ans.size() - 1;
        while(idx >= 0 and ans[idx]==' ') idx--;
        
        return ans.substr(0, idx+1);
    }
};