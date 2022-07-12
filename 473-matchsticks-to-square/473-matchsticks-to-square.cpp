class Solution {
public:
    
    bool calc(vector<int> &v, int i, int s1, int s2, int s3, int s4)
    {   
        if(s1<0 || s2<0 || s3<0 || s4<0)
            return false;
        
        if(i==v.size()){
            if(s1==0 && s2==0 && s3==0 && s4==0){
                return true;
            }
            return false;
        }
        
        if(v[i]<=s1 && calc(v,i+1,s1-v[i],s2,s3,s4))
            return true;
        
        if(v[i]<=s2 && calc(v,i+1,s1,s2-v[i],s3,s4))
            return true;
            
        if(v[i]<=s3 && calc(v,i+1,s1,s2,s3-v[i],s4))
            return true;
        
        if(v[i]<=s4 && calc(v,i+1,s1,s2,s3,s4-v[i]))
            return true;
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        bool ans = false;
        
        int sum = 0;
        for(int i : matchsticks){
            sum += i;
        }
        
        if(sum%4 != 0)
            return false;
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        for(int i : matchsticks){
            if(i > sum/4)
                return false;
        }
        
        return calc(matchsticks,0,sum/4,sum/4,sum/4,sum/4);
        
    }
};