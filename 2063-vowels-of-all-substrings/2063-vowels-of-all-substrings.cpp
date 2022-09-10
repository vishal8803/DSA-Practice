class Solution {
public:
    bool isVowel(char ch) {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        
        return false;
    }
    
    long long countVowels(string word) {
        long long count = 0;
        int n = word.size();
        for(int i = 0; i < word.size(); i++) {
            if(isVowel(word[i])) {
                long long int l = (n-i);
                count += (i*l) + l;
            }
        }
        
        return count;
    }
};