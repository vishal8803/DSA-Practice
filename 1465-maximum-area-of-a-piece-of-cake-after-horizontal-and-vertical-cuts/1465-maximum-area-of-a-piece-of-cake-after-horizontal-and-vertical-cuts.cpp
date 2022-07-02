class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int mxW = 0;
        int mxH = 0;
        
        mxH = max(mxH, horizontalCuts[0]);
        
        for(int i = 1; i < horizontalCuts.size(); i++){
            mxH = max(mxH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        mxH = max(mxH, h-horizontalCuts[horizontalCuts.size()-1]);
        
        mxW = max(mxW, verticalCuts[0]);
        
        for(int i = 1; i < verticalCuts.size(); i++){
            mxW = max(mxW, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        mxW = max(mxW, w-verticalCuts[verticalCuts.size()-1]);
        
        long long ans = ((long long)mxH*(long long)mxW)%1000000007;
        
        return ans;
    }
};