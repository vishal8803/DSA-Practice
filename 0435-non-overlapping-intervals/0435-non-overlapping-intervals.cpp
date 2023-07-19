class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp = intervals[0];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(temp[1] <= intervals[i][0]){
                temp = intervals[i];
                continue;
            }
            if(temp[1]<=intervals[i][1]){
                count++;
                continue;
            }else if(temp[1]>intervals[i][1]){
                count++;
                temp = intervals[i];
                continue;
            }
        }
        return count;
    }
};