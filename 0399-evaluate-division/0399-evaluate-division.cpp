class Solution {
public:
    double calc(map<string,vector<pair<string,double>>>& mp, string source, string target){
        // double val = 1.0;
        queue<pair<string,double>> q;
        map<string,bool> visited;
        q.push({source,1.0});
        visited[source] = true;
        
        while(!q.empty()){
            string t = q.front().first;
            double val = q.front().second;
            q.pop();
            
            if(t==target && mp.find(t) != mp.end()){
                return val;
            }
            
            for(auto it : mp[t]){
                if(!visited[it.first]){
                    q.push({it.first,val*it.second});
                    visited[it.first] = true;
                }
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> mp;
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            mp[a].push_back({b,values[i]});
            double temp = 1.0/values[i];
            mp[b].push_back({a,temp});
        }
        vector<double> ans;
        for(vector<string> q : queries){
            string source = q[0];
            string target = q[1];
            
            ans.push_back(calc(mp,source,target));
        }
        
        return ans;
    }
};