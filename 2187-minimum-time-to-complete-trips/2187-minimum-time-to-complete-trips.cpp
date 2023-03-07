class Solution {
public:
    bool canCompleteTripsInTheGivenTime(vector<int> &time, long long gt, int tt){
        long long count = 0;
        
        for(int i : time){
            count += (long long)gt/(long long)i ;
        }
        if(count>=tt)
            return true;
        
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size()==1){
            return (long long)totalTrips*time[0] ;
        }
        
        
        long long st = 1;
        long long end = 1LL * *max_element(time.begin(), time.end())*totalTrips;
        long long result = LLONG_MAX;
        while(st<=end){
            long long mid = (st) + (end-st)/2LL;
            
            if(canCompleteTripsInTheGivenTime(time, mid,totalTrips)){
                result = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return result;
    }
};