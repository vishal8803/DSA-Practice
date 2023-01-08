class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
            return n;
        
        int ans = 2;
        map<double,int> mp;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                double c;
                if(points[j][0]-points[i][0]==0)
                {
                    c=DBL_MAX;
                }else{
                c = (double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);    
                }
                mp[c]++;
            }
            for(auto it = mp.begin() ; it!= mp.end() ; it++)
             {
                 ans = max(ans,1+it->second) ;
             }
            mp.clear() ;
        }
        return ans;
    }
};