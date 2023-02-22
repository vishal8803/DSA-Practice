class Solution {
public:
    bool calc(vector<int>& a, int days, int capacity){
        int s =0 ,c=1 ;
        for(int i =0 ; i<a.size() ;i++)
        {
            s=s+a[i] ;
            if(s>capacity)
            {
                c++ ;
                s=a[i];
            }
            if(c>days)
            {
                return false ;
            }
        }
        return true ;
    }
    int shipWithinDays(vector<int>& a, int days) {
        int st = *max_element(a.begin(),a.end());
        int end = accumulate(a.begin(),a.end(),0);
        
        int res =0 ;
        while(st<=end){
            int mid = (st+end)/2;
            if(calc(a,days,mid)){
                res = mid;
                end = mid - 1;
            }else{
                st= mid+1;
            }
        }
        return res;
    }
};