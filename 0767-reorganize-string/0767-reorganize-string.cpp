class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(char c : s)
            mp[c]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second,it->first});
        }
        pair<int,char> block = pq.top();
        pq.pop();
        
        string ans = "";
        ans += block.second;
        block.first--;
        
        
        
        while(!pq.empty()){
            pair<int,char> temp = pq.top();
            pq.pop();
            ans += temp.second;
            // cout<<ans<<endl;
            temp.first--;
            if(block.first != 0){
                pq.push(block);
            }
            block = temp;
        }
        
        if(block.first>0)
            return "";
        
        return ans;
    }
};