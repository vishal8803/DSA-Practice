class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i =0 ; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int t = q.front();
                q.pop();
                order.push_back(t);
                for(auto it : adj[t]){
                    if(indegree[it]!=0){
                        indegree[it]--;
                        if(indegree[it]==0)
                            q.push(it);
                    }
                }
            }
        }
        if(order.size()!=numCourses)
            return {};
        
        return order;
    }
};