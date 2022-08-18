class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        
        for(int i : arr) mp[i]++;
        
        vector<int> v;
        
        for(auto it : mp) {
            v.push_back(it.second);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
            count++;
            if(sum >= n/2) return count;
        }
        return -1;
    }
};