class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> length;
        
        for(string word : words) {
            length.push_back(word.length());
        }
        
        vector<int> bits;
        
        for(string word : words){
            int t = 0;
            for(int i = 0; i < word.length(); i++) {
                t = t | (1<<(word[i]-'a'));
            }
            bits.push_back(t);
        }
        
        int ans = 0;
        
        for(int i = 0; i < bits.size(); i++) {
            for(int j = i+1; j < bits.size(); j++) {
                if((bits[i]&bits[j])==0){
                    ans = max(ans, length[i]*length[j]);
                }
            }
        }
        
        return ans;
    }
};