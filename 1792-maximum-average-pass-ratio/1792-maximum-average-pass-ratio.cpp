class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int es) {
int n  = c.size();
        double avg  = 0,ans = 0;
        priority_queue<pair<double,int>> pq;

        for(int i = 0;i<n;i++)
        {
            double diff =(double)(c[i][0]+1)/(double)(c[i][1]+1)-(double)c[i][0]/(double)c[i][1];
            pq.push({diff,i});
        }
        
        while(es--)
        {
           int i = pq.top().second;
           pq.pop();
           c[i][0]+=1;
           c[i][1]+=1;
           double diff = (double)(c[i][0]+1)/(double)(c[i][1]+1)-(double)c[i][0]/(double)c[i][1];
           pq.push({diff,i});
        }

        for(int i = 0;i<n;i++)
        {
            avg = (double)c[i][0]/(double)c[i][1];
            ans+=avg;
        }
        return ans/(double)n;
    }
};