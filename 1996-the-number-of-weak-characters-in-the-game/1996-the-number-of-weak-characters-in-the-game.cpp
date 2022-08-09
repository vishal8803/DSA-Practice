class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](vector<int> &property1, vector<int> &property2){
            return property1[0] < property2[0];
        });
        
        
        map<int, vector<int>> mp;
        
        for(auto property : properties) {
            int a = property[0];
            int d = property[1];
            mp[a].push_back(d);
        }
        
        vector<int> mxValues;
        for(auto it : mp) {
            int mx = INT_MIN;
            for(auto i : it.second) {
                mx = max(mx, i); 
            }
            mxValues.push_back(mx);
        }
        vector<int> temp(mxValues.size());
        temp[mxValues.size()-1] = mxValues[mxValues.size()-1];
        for(int i = mxValues.size()-2; i>=0; i--) {
            temp[i] = max(temp[i+1],mxValues[i]);
        }
        
        int count = 0;
        int idx = 0;
        
        for(auto it : mp) {
            
            for(auto i : it.second) {
                if(idx+1 < mxValues.size() && i < temp[idx+1]){
                    count++;
                } 
            }
            idx++;
        }
        return count;
    }
};