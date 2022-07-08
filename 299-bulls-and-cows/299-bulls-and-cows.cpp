class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        
        vector<int> s1(10,0), s2(10,0);
        
        for(int i = 0; i < secret.length(); i++){
            s1[secret[i]-'0']++;
            s2[guess[i]-'0']++;
        }
        
        for(int i = 0; i < secret.length(); i++){
            if(secret[i]==guess[i]){
                bulls++;
                s1[secret[i]-'0']--;
                s2[guess[i]-'0']--;
            }
        }
        
        for(int i = 0; i < 10; i++){
            if(s1[i]>0 && s2[i]>0){
                cows += min(s1[i], s2[i]);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};