class Solution {
public:
    vector<string> splitString(string s){
        vector<string> ans;
        
        stringstream ss(s);
        string word;
        
        while(ss >> word){
            ans.push_back(word);
        }
        
        return ans;
    }
    
    float round(float var)
    {
        float value = (int)(var * 100 + .5);
        return (float)value / 100;
    }

    string discountPrices(string sentence, int discount) {
        vector<string> temp = splitString(sentence);
        string res = "";
        
        double dis = discount/100.0;
        
        for(string s : temp){
            
            if(s[0] != '$' || s.length()==1){
                res += s + " ";
                continue;
            }
                
            
            long long num = 0;
            bool isValid = true;
            
            for(int i = 1; i<s.length(); i++){
                if(s[i]>='0' && s[i]<='9'){
                    num = num*10 + (s[i]-'0');
                }else{
                    isValid = false;
                    break;
                }
            }
            
            if(isValid==false){
                res += s + " ";
                continue;
            }
            
            long long t = num;
            long double ans = (long double)(t) - (long double)(t)*(long double)dis ;
            
            res += "$";
            string r = to_string(ans);
            
            
            int k = 0;
            while(k<r.length() && r[k] != '.'){
                res += r[k];
                k++;
            }
            res += r[k];
            res += r[k+1];
            res += r[k+2];
            res += " ";
            
        }
        return res.substr(0,res.length()-1);
        
    }
};