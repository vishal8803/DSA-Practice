class Solution {
public:
    string calc(int n){
        if(n==1)
            return "1";
        
        string temp = calc(n-1);
        string ans = "";
        int i=0; 
        while(i<temp.length()){
            int count =0 ;
            char ch = temp[i];
            while(i<temp.length() && temp[i]==ch){
                count++;
                i++;
            }
            ans = ans + to_string(count)+ch;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        return calc(n);
    }
};