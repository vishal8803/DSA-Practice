class Solution {
public:
    void dfs(map<string,priority_queue<string,vector<string>, greater<string>>> &mp,  vector<string> &ans, string temp)
    {
       priority_queue<string,vector<string>, greater<string>> it = mp[temp] ;
        // cout<<temp<<endl;
            while(mp[temp].size()>0)
            {
                string s = mp[temp].top();
                mp[temp].pop();
                dfs(mp,ans,s);
            }
        ans.push_back(temp);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,priority_queue<string,vector<string>, greater<string>>> mp;
        
        for(int i=0; i<tickets.size(); i++)
        {
            mp[tickets[i][0]].push(tickets[i][1]);
        }
        
        vector<string> ans;
        dfs(mp,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};