class MyCalendar {
public:
    vector<pair<int,int>> v;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.size()==0) {
            v.push_back({start,end});
            return true;
        }
        
        for(int i = 0; i < v.size(); i++) {
            int st = v[i].first;
            int ed = v[i].second;
            
            if(end <= st || ed <= start) continue;
            
            if((st >=start && ed <=end) || (start >= st && end<=ed) || (st>=start && ed>=end) || (start>=st && end>=ed)) return false;
        }
        v.push_back({start,end});
        sort(v.begin(), v.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */