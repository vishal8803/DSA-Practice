class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int ctot = 0;
        int llv = 1;
        
        while(ctot < label) {
            ctot += llv;
            llv = llv<<1;
        }
        
        llv/=2;
        
        while(label != 1) {
            ans.push_back(label);
            int comp = 3*llv - label - 1;
            label = comp/2;
            llv/=2;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};