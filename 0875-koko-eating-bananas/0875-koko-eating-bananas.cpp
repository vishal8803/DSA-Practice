class Solution {
public:
    bool check(vector<int> &piles, int h, int ms){
        long long count = 0;
        // cout<<ms<<endl;
        for(int i=0; i<piles.size();  i++){
            double x = ((double)piles[i]/(double)ms);
            count += ceil(x);
        }
        
        if(count<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int high = *max_element(piles.begin(),piles.end());
        int speed = INT_MAX;
        
        while(l<=high){
            int mid = (l+high)/2 ;
            // cout<<mid<<" ";
            if(check(piles,h,mid)){
                speed = min(speed,mid);
                high=mid-1;
            }else{
                l=mid+1;
            }
        }
        return speed;
    }
};