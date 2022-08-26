class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        string temp = s;
        do {
            int t = stoi(s);
            if(s[0] != '0' && (t&(t-1))==0) return true;
            next_permutation(s.begin(), s.end());
        } while(s != temp);
        
        return false;
    }
};