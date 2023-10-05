class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int elem1=-1,elem2=-1,cnt1=0,cnt2=0 ;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(elem1 == nums[i])
            {
                cnt1++ ;
            }else if(elem2 == nums[i])
            {
                cnt2++ ;
            }else if(cnt1==0)
            {
                elem1=nums[i] ;
                cnt1=1 ;
            }else if(cnt2==0)
            {
                elem2 = nums[i] ;
                cnt2=1 ;
            }else
            {
                cnt1-- ;
                cnt2-- ;
            }
        }
        int fc1 = 0,fc2= 0;
        vector<int> ans ;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==elem1)
            {
                fc1++ ;
            }else if(nums[i]==elem2)
            {
                fc2++ ;
            }
            
        }
        
        int n = nums.size() ;
        if(fc1 > n/3)
        {
            ans.push_back(elem1) ;
        }
        if(fc2 > n/3)
        {
            ans.push_back(elem2) ;
        }
        return ans ;
    }
};