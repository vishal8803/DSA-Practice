class Solution {
public:
    string solveEquation(string e) {
        vector<string> x;
        vector<string> c;
        
        int i = 0;
        bool f = false;
        while(i<e.length()){
            if(e[i]=='=')
            {
                f = true;
                i++;
                continue;
            }
            
            string s = "";
            bool flag = false;
            
            if(e[i]=='-'){
                flag = true;
                i++;
            }else if(e[i]=='+'){
                i++;
            }
            
            while(i<e.length()){
                if((e[i] == '-' || e[i] =='+' || e[i] == '='))
                    break;
                s += e[i];
                i++;
                
            }
            
            int len = s.length();
            
            if(!f){    
                if(s[len-1]=='x'){
                    string t = s.substr(0,len-1);
                    
                    string ans = (t.length()==0 ? "1":t);
                    
                    x.push_back((flag?"-":"")+ans);
                }else{
                    c.push_back((flag?"-":"")+s);
                }
            }else{
                if(s[len-1]=='x'){
                    string t = s.substr(0,len-1);
                    string ans = (t.length()==0 ? "1":t);
                    x.push_back((!flag?"-":"")+ans);
                }else{
                    c.push_back((!flag?"-":"")+s);
                }
            }
        }
        // return "";
        vector<int> xd, cd;
        for(string s : x){
            // cout<<s<<endl;
            xd.push_back(stoi(s));
        }
        for(string s : c){
            // cout<<s<<endl;
            cd.push_back(stoi(s));
        }
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i : xd){
            sum1 += i;
        }
        
        for(int i : cd){
            sum2 += i;
        }
        if(sum2==0)
        {
            if(sum1==0){
                return "Infinite solutions";
            }else{
                return "x=0";
            }
        }else if(sum1==0){
            return "No solution";
        }
        
        int ans = sum2/sum1;
        
        ans = -1*ans;
        return "x="+to_string(ans);
    }
};