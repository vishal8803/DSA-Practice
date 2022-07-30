class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        while(a>0 || b>0) {
            bool aw = false;
            if(ans.length()>=2 && ans[ans.size()-1]==ans[ans.size()-2]) {
                if(ans[ans.size()-1]=='b'){
                    aw = true;
                } 
            } else {
                if(a>b){
                    aw = true;
                }
            }
            if(aw) {
                ans += 'a';
                a--;
            } else{
                ans += 'b';
                b--;
            }
        }
        
        return ans;
    }
};