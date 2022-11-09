class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        string ans = "";
        
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        priority_queue<pair<char,int>, vector<pair<char,int>>> pq;
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                pq.push({'a' + i, freq[i]});
            }
        }
        
        while(pq.size() > 0) {
            auto it = pq.top();
            pq.pop();
            int count = it.second;
            
            for(int i = 0; i < repeatLimit and count > 0; i++) {
                ans += it.first;
                count--;
            }
            
            if(count > 0 and pq.size() > 0) {
                auto it2 = pq.top();
                pq.pop();
                
                ans += it2.first;
                if(it2.second > 1) {
                    pq.push({it2.first, it2.second - 1});
                }
                pq.push({it.first, count});
            }
        }
        
        return ans;
    }
};