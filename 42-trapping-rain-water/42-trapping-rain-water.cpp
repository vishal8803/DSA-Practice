class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        if(n==0 || n==1 || n==2)
            return 0 ;
        int lmx[n] ;
        int rmx[n] ;
        lmx[0] = height[0] ;
        rmx[n-1] =height[n-1] ;
        for(int i=1 ; i<n ; i++)
        {
            lmx[i] = max(lmx[i-1] , height[i]) ;
        }
        for(int i =n-2 ; i>=0 ; i--)
        {
            rmx[i] = max(height[i] , rmx[i+1]) ;
        }
        int ans =0 ;
        for(int i =0 ;i<n ;i++)
        {
           ans=ans+min(lmx[i],rmx[i])-height[i] ;
        }
        return ans;   
    }
};