class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        if(sp.size()==1)
            return 0;
        
        if(sp.size()==2){
            return 1;
        }
        
        sort(sp.begin(),sp.end(),[&](vector<int> &v1, vector<int> &v2){
            return (v2[0]-v1[0])>0;
        });
        
        long long count = 1;
        
        
        vector<int> sp1 = sp[0];
        vector<int> sp2 = sp[1];
            
        long double prev = (long double)(sp2[1]-sp1[1])/(long double)(sp2[0]-sp1[0]);
        
        for(int i = 1; i < sp.size()-1; i++){
            vector<int> s1 = sp[i];
            vector<int> s2 = sp[i+1];
            
            long double x = (long double)(s2[1]-s1[1])/(long double)(s2[0]-s1[0]);
            
            if(prev != x){
                count++;
                prev = x;
            }
            
        }
        return count;
    }
};

// [[72,98],[62,27],[32,7],[71,4],[25,19],[91,30],[52,73],[10,9],[99,71],[47,22],[19,30],[80,63],[18,15],[48,17],[77,16],[46,27],[66,87],[55,84],[65,38],[30,9],[50,42],[100,60],[75,73],[98,53],[22,80],[41,61],[37,47],[95,8],[51,81],[78,79],[57,95]]
/*

*/