/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        
        map<int,vector<int>> adj;
        map<int,int> importance;
        
        for(int i = 0; i < employees.size(); i++){
            vector<int> t = employees[i]->subordinates;
            int id = employees[i]->id;
            int imp = employees[i]->importance;
            importance[id] = imp;
            for(int emp : t){
                adj[id].push_back(emp);
            }
        }
        
        queue<int> q;
        q.push(id);
        int ans = 0;
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans += importance[t];
            for(auto it : adj[t]){
                q.push(it);
            }
        }
        return ans;
    }
};