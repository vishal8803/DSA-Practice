class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int> p1, vector<int> p2){
            if(p1[0] == p2[0]){
                return p1[1] < p2[1]; 
            }
            return p1[0] > p2[0];
        });
        
        list<pair<int,int>> l;
        
        for(int i = 0; i < people.size(); i++){
            list<pair<int,int>>::iterator it = l.begin();
            advance(it,people[i][1]);
            l.insert(it,{people[i][0],people[i][1]});
        }
        
        vector<vector<int>> ans;
        
        for(auto it : l){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};