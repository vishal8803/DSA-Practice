class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lt, rt;
        
        if(left.size() != 0)
            lt = *max_element(left.begin(), left.end());
        
        if(right.size() != 0)
            rt = n - *min_element(right.begin(), right.end());
        
        if(left.size() == 0) return rt;
        if(right.size() == 0) return lt;
        
        return max(lt, rt);
    }
};