class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq; 
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second,it->first});
        }
        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char c = pq.top().second;
            for(int i=0; i<freq; i++){
                ans+=c;
            }
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};