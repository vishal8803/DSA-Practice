class Solution {
    public int removeElement(int[] nums, int val) {
        int count = 0;
        int i = 0;
        
        for(int j = 0; j < nums.length; j++) {
            if(nums[j]==val) continue;
            nums[i] = nums[j];
            i++;
            count++;
        }
        
        return count;
    }
}