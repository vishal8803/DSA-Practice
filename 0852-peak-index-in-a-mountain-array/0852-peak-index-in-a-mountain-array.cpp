class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int st = 0;
        int end = a.size()-1;
        
        while(st<=end){
            int mid = (st+end)/2;
            if(mid==0){
                if(a[mid]>a[mid+1])
                    return mid;
                else
                    st = mid+1;
            }else if(mid==a.size()-1){
                if(a[mid]>a[mid-1])
                    return mid;
                else
                    end = mid-1;
            }else{
                if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
                    return mid;
                else if(a[mid+1]>a[mid]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};