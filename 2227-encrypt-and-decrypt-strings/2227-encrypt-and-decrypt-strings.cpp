    
class Encrypter {
    
public:
    map<char,string> mp1;
    map<string, int> mp2;
    
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++) {
            mp1[keys[i]] = values[i];
        }
        
        for(string s : dictionary) {
            mp2[encrypt(s)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(char ch : word1) {
            if(mp1.find(ch) == mp1.end()) return "";
            ans += mp1[ch];
        }
        
        return ans;
    }
    
    int decrypt(string word2) {
        return mp2[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */