class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval) ;
        sort(intervals.begin(),intervals.end()) ;
        vector<vector<int>> ans ;
        vector<int> t = intervals[0] ;
        for(int i=1 ; i<intervals.size() ; i++)
        {
            if(t[1]>=intervals[i][0])
            {
                t[0] = min(t[0],intervals[i][0]);
                t[1] = max(t[1],intervals[i][1]);
            }else
            {
                ans.push_back(t);
                t=intervals[i] ;
            }
        }
        ans.push_back(t) ;
        return ans ;
    }
};