class Solution {
public:
    
    int countUnique(vector<int> &a) {
        int count = 0;
        for(int i : a) {
            if(i >= 1) count++;
        }
        return count;
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int mx = 0;
        int t = s.length();
        for(int size = minSize; size <= min(maxSize,t); size++) {
            int count = 0;
            int i = 0;
            int j = 0;
            vector<int> mp(26,0);
            unordered_map<string,int> mp2;
            string test = "";
            while(j < s.length()) {
                mp[s[j]-'a']++;
                test += s[j];
                if(j-i+1 < size) {
                    j++;
                } else if(j-i+1==size) {
                    if(countUnique(mp)<=maxLetters) {
                        mp2[test]++;
                    }
                    mp[s[i]-'a']--;
                    i++;
                    j++;
                    test = test.substr(1);
                }
            }
            
            for(auto it : mp2) {
                count = max(count,it.second);
            }
            mx = max(mx,count);
        }
        
        return mx;
    }
};