class Solution {
public:
    int calc(vector<int> & a, int target){
        int st =0 ;
        int end =a.size()-1 ;
        while(st<end)
        {
            int mid=(st+end)/2 ;
            if(a[st]==a[mid] && a[mid]==a[end])
                return INT_MAX;
            if(a[mid]<=a[end])
            {
                end=mid ;
            }
            else
            {
                st=mid+1 ;
            }
        }
        return st;
    }
    
    bool isPresent(vector<int> &a, int st, int end, int target)
    {
        while(st<=end)
        {
            int mid = (st+end)/2;
            if(a[mid]==target)
                return true;
            else if(a[mid]>target)
            {
                end = mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int idx = calc(nums, target);
        if(idx==INT_MAX){
            for(int i =0 ;i<nums.size(); i++){
                if(nums[i]==target)
                    return true;
            }
            return false;
        }
        // cout<<idx<<endl;
        
        if(isPresent(nums ,0, idx,target)==true)
            return true;
        
        if(isPresent(nums,idx,nums.size()-1,target)==true)
            return true;
        
        return false;
    }
};