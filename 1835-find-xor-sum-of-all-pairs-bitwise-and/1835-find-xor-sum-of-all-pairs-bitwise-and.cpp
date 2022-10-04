class Solution {
public:
    int getXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int xr1 = 0;
        int xr2 = 0;
        
        for(int i = 0; i < nums2.size(); i++) {
            xr1 = xr1 ^ nums2[i];
        }

        for(int i = 0; i < nums1.size(); i++) {
            xr2 = xr2 ^ nums1[i];
        }
        
        return (xr1 & xr2);
    }
};