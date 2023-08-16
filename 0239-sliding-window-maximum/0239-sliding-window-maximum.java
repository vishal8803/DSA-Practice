class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        
        int len = nums.length;
        
        int[] array = new int[len - k + 1];
        int it = 0;
        int j = 0;
        int i = 0;
        while(j < len) {
            while(dq.size() > 0 && dq.getLast() < nums[j]) {
                dq.removeLast();
            }
            dq.addLast(nums[j]);
            if(j - i + 1 < k) {
                j++;
            } else if(j - i + 1 == k) {
                array[it++] = dq.getFirst();
                if(dq.getFirst() == nums[i]) {
                    dq.removeFirst();
                }
                i++;
                j++;
            }
        }
        
        return array;
    }
}