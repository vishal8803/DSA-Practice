class TopVotedCandidate {
public:
    vector<int> ans;
    vector<int> times;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        int count = 0;
        int t = -1;
        map<int,int> mp;
        
        for(int i = 0; i < persons.size(); i++) {
            mp[persons[i]]++;
            if(count <= mp[persons[i]]) {
                count = mp[persons[i]];
                t = persons[i];
            }
            ans.push_back(t);
        }
        
    }
    
    int q(int t) {
        int st = 0;
        int end = times.size() - 1;
        int idx = -1;
        
        while(st <= end) {
            int mid = (st + end)/2;
            if(times[mid] > t) {
                end = mid - 1;
            } else {
                idx = mid;
                st = mid + 1;
            }
        }
        
        return ans[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */