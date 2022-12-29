class Solution {
public:
    struct ComparePair {
        bool operator()(pair<int,int> const &p1, pair<int,int> const &p2)
        {
            if(p1.second == p2.second) return p1.first > p2.first;
            return p1.second > p2.second;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for(int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        // for(auto task : tasks) {
        //     cout<<task[0]<<" "<<task[1]<<" "<<task[2]<<endl;
        // }
        vector<int> ans;
        int i = 0;
        long long time = tasks[0][0];
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, ComparePair> pq;
        
        while(i < tasks.size() || pq.size() > 0) {
            if(i < tasks.size() and time < tasks[i][0] and pq.size() == 0) time = tasks[i][0];
            while(i < tasks.size() and tasks[i][0] <= time) {
                pq.push({tasks[i][2],tasks[i][1]});
                i++;
            }
            
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
            time += it.second;
        }
        
        
        return ans;
    }
};