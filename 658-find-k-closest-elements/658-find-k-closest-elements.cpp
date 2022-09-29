class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<pair<int,int>> v;
        
        for(int i = 0; i < arr.size(); i++) {
            v.push_back({abs(arr[i]-x),arr[i]});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> &p1, pair<int,int> &p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        
        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};