class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num==0)
            return "0";
        
        bool flag;
        
        if((num<0 && den<0) || (num>0 && den>0)){
            flag = 0;
        }else{
            flag = 1;
        }
        
        long long n = (num);
        long long d = (den);
        
        if(n<0){
            n = -1*n;
        }
        if(d<0){
            d = -1*d;
        }
        
        string ans = "";
        long long q = n/d;
        long long r = n%d;
        ans += to_string(q);
        
        if(r==0){
            if(flag)
            {
                return "-" + ans;
            }
            return ans;
        }else{
            ans += ".";
            map<int,int> mp;
            
            while(r!=0){
                if(mp.find(r) != mp.end()){
                    int pos = mp[r];
                    string nans = ans.substr(0,pos) + "(" + ans.substr(pos,ans.length()) + ")";
                    ans = nans;
                    break;
                }else{
                    mp[r] = ans.length();
                    r *= 10;
                    q = r/d;
                    r = r%d;
                    ans += to_string(q);
                }
            }
            if(flag)
            {
                return "-" + ans;
            }
            return ans;
        }
        return "";
    }
};