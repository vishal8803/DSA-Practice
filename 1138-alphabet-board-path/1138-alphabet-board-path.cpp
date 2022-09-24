class Solution {
public:
    string calc(int x, int y, int fx, int fy, int ch) {
    // cout<<fx<<","<<fy<<endl;
    int r=(fx-x);
    int c=(fy-y);
    string ans;
    if(r<0){
        for(int i=0;i<abs(r);i++){
            ans+="U";
        }
    }
    else{
            for(int i=0;i<r-1;i++){
                ans+="D";
            }
        if(ch!='z' && r!=0){
            ans+="D";
        }
    }
        if(c<0){
            for(int i=0;i<abs(c);i++){
            ans+="L";
        }   
        }
        else{
            for(int i=0;i<c;i++){
            ans+="R";
        }
        }
        if(ch=='z' && r!=0){
            ans+="D";
        }
        ans+="!";
        return ans;
   }
    
    string alphabetBoardPath(string target) {
        vector<string> boards = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        
        int x = 0;
        int y = 0;
        string ans = "";
        
        map<char, pair<int,int>> mp;
        
        for(int i = 0; i < boards.size(); i++) {
            for(int j = 0; j < boards[i].size(); j++) {
                mp[boards[i][j]] = {i,j};
            }
        }
        
        for(int i = 0; i < target.size(); i++) {
            char ch = target[i];
            pair<int,int> t = mp[ch];
            ans += calc(x,y,t.first, t.second, ch);
            x = t.first;
            y = t.second;
        }
        
        return ans;
    }
};