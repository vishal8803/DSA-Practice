
class Solution {
public:
    int ciel(vector<int> &heaters , int target)
    {
        if(heaters.size()==1)
            return heaters[0] ;
        int st =0 , end=heaters.size()-1 ;
        int res = -1 ;
        while(st<=end)
        {
            int mid = (st+end)/2 ;
            if(heaters[mid]==target)
            {
                return target ;
            }else if(heaters[mid]>target)
            {
                res = heaters[mid] ;
                end = mid-1 ;
            }else
            {
                st=mid+1 ;
            }
        }
        return res ;
    }
    
    int floor(vector<int> &heaters , int target)
    {
        if(heaters.size()==1)
            return heaters[0] ;
        int st=0,end = heaters.size()-1 ;
        int res = -1 ;
        while(st<=end)
        {
            int mid = (st+end)/2 ;
            if(heaters[mid]==target)
            {
                return target ;
            }else if(heaters[mid]>target)
            {
               
                end = mid-1 ;
            }else
            {
                 res = heaters[mid] ;
                st=mid+1 ;
            }
        }
        return res ;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
         int mx = 0 ;
        sort(heaters.begin(),heaters.end()) ;
        sort(houses.begin(),houses.end()) ;
        for(int i=0 ; i<houses.size() ; i++)
        {
            int c = ciel(heaters,houses[i]);
            int f = floor(heaters,houses[i]);
            int mx1 = INT_MAX;
            int mx2 = INT_MAX ;
            if(c != -1)
            {
                mx1 = abs(houses[i]-c) ;
            }
            if(f!= -1)
            {
                mx2 = abs(houses[i]-f) ;
            }
            mx=max(mx,min(mx1,mx2)) ;
        }
        return mx ;
    }
};