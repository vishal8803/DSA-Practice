class Solution {
public:
    struct Compare{
      bool operator()(pair<int,string> p1,pair<int,string> p2){
          if(p1.first<p2.first)
              return false;
          else if(p1.first>p2.first)
              return true;
          else{
              return (p1.second<p2.second);
          }
      }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        
        for(string word : words){
            mp[word]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> pq;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<string> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};