class NumArray {
public:
    int seg[4 * 100005];
    vector<int> temp;
    
    void buildSegmentTree(vector<int> &a, int idx, int low, int high) {
        if(low==high) {
            seg[idx] = a[low];
            return;
        }
        
        int mid = (low+high)/2;
        buildSegmentTree(a,2*idx+1,low,mid);
        buildSegmentTree(a,2*idx+2,mid+1,high);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    NumArray(vector<int>& nums) {
        temp = nums;
        buildSegmentTree(nums,0,0,nums.size()-1);
    }
    
    void updateSegmentTree(int idx, int low, int high, int index, int val) {
        if(low==high) {
            seg[idx] += val;
        } else {
            int mid = (low+high)/2;
            if(index <= mid && index >= low) updateSegmentTree(2*idx+1, low, mid, index,val);
            else updateSegmentTree(2*idx + 2, mid+1, high, index,val);
            seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        }
    }
    
    void update(int index, int val) {
        int diff = val-temp[index];
        temp[index] = val;
        updateSegmentTree(0, 0, temp.size()-1, index, diff);
    }
    
    int getSumInRange(int idx, int low, int high, int left, int right) {
        if(low >= left && high<=right) return seg[idx];
        
        else if(high < left || right < low) return 0;
        
        int mid = (low+high)/2;
        int ltSum = getSumInRange(2*idx+1,low,mid,left,right);
        int rtSum = getSumInRange(2*idx+2,mid+1,high,left,right);
        return ltSum + rtSum;
    }
    
    int sumRange(int left, int right) {
        return getSumInRange(0, 0, temp.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */