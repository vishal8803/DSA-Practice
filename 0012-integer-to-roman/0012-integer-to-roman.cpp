class Solution {
public:
    
    string intToRoman(int num) {
        vector<pair<char,int>> v = {{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        string ans = "";
        
        while(num>0){
            if(num==4 || num==3 || num==2 || num==9){
                if(num==4){
                    ans+="IV";
                }else if(num==3){
                    ans += "III";
                }else if(num==2){
                    ans += "II";
                }else if(num==9){
                    ans += "IX";
                }
                break;
            }
            if(num>=40 && num<50){
                ans +="XL";
                num = num - 40;
                continue;
            }else if(num>=90 && num<100){
                ans += "XC";
                num = num-90;
                continue;
            }else if(num>=400 && num<500){
                ans += "CD";
                num -= 400;
                continue;
            }else if(num>=900 && num<1000){
                ans += "CM";
                num -= 900;
                continue;
            }
            for(int i = 0; i < v.size(); i++){
                int d = v[i].second;
                char ch = v[i].first;
                if(num/d >= 1){
                    ans += ch;
                    num = num-d ;
                    break;
                }
            }
        }
        return ans;
    }
};