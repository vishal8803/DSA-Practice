class Solution {
public:
    int binarySearch(vector<int> &a , int st, int end,int target){
        while(st<=end){
            int mid = (st+end)/2;
            if(a[mid]==target){
                return mid;
            }else if(a[mid]>target){
                end = mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int st =0,end=nums.size()-1;
        while(st<end){
            int mid=(st+end)/2;
            if(nums[mid]<nums[end])
            {
                end=mid;
            }
            else
            {
                st=mid+1;
            }
        }
        int ans1 = binarySearch(nums,0,st-1,target);
        if(ans1!=-1){
            return ans1;
        }
        return binarySearch(nums,st,nums.size()-1,target);
    }
};