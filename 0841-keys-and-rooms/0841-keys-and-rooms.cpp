class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int node, vector<bool> &visited){
        visited[node] = true;
        for(auto it : rooms[node]){
            if(!visited[it]){
                dfs(rooms,it,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        dfs(rooms,0,visited);
        for(int i = 0; i < visited.size(); i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};