class SnapshotArray {
public:
    int snp = 0;
    map<int,vector<pair<int,int>>> mp;
    
    int calc(vector<pair<int,int>>& v, int id) {
        if(v.size()==0) {
            return 0;
        }
        
        int st = 0;
        int end = v.size() - 1;
        int res = -1;
        
        while(st<=end) {
            int mid = (st+end)/2;
            if(v[mid].first > id) {
                end = mid - 1;
            } else {
                res = mid;
                st = mid + 1;
            }
        }
        if(res==-1) return 0;
        return v[res].second;
    }
    
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        if(mp.find(index)==mp.end() || mp[index].size()==0){
            mp[index].push_back({snp,val});
        }
        else {
            // auto it = mp[index];
            int n = mp[index].size();
            if(mp[index][n-1].first == snp) {
                mp[index][n-1].second = val;
                // mp[index] = it;
            } else {
                mp[index].push_back({snp,val});
            }
        } 
            
    }
    
    int snap() {
        return snp++;
    }
    
    int get(int index, int snap_id) {
        return calc(mp[index], snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */