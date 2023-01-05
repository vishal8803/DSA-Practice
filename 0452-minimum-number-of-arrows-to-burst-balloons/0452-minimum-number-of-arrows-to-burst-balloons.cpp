class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count=1;
        vector<int> point = points[0];
        
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0]<=point[1]){
                point[0]=max(points[i][0],point[0]);
                point[1]=min(points[i][1],point[1]);
            }else{
                count++;
                point=points[i];
            }
        }
        return count;
    }
};