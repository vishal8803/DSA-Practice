class Solution {
public:
    void solveConfigeration(string &s, int i, int j){
        if(s[i]=='L' && s[j]=='L'){
            for(int k = i+1; k<j; k++){
                s[k] = 'L';
            }
        }else if(s[i]=='L' && s[j]=='R'){
            
        }else if(s[i]=='R' && s[j]=='L'){
            int diff = j-i;
            int mid = (i+j)/2;
            if(diff%2){
                for(int k = i+1; k<=mid; k++){
                    s[k]='R';
                }
                for(int k = mid+1; k<j; k++){
                    s[k]='L';
                }
            }else{
                for(int k = i+1; k<mid; k++){
                    s[k]='R';
                }
                for(int k = mid+1; k<j; k++){
                    s[k]='L';
                }
            }
        }else{
            for(int k = i+1; k<j; k++){
                s[k] = 'R';
            }
        }
    }
    string pushDominoes(string dominoes) {
        int i = 0;
        int j = 0;
        
        string temp = "L"+dominoes+"R";
        
        while(j<temp.length()){
            while(j<temp.length() && temp[j]=='.')
                j++;
            if(j-i>1)
                solveConfigeration(temp,i,j);
            
            i=j;
            j++;
        }
        
        for(int i = 0; i < dominoes.length(); i++){
            dominoes[i] = temp[i+1];
        }
        
        return dominoes;
    }
};