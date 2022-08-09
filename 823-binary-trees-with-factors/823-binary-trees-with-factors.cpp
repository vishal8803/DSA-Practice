class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<long long,long long> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        int MOD = 1000000007;
        sort(arr.begin(),arr.end());
        for(int i=1; i<arr.size(); i++){
            long long count =0 ;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0){
                    int t = arr[i]/arr[j];
                    if(mp.find(t)!=mp.end()){
                        count+=(mp[arr[j]]%MOD*mp[t]%MOD)%MOD;
                    }
                }
            }
            mp[arr[i]]=(mp[arr[i]]+count)%MOD;
        }
        int ans =0 ;
        for(auto it = mp.begin(); it!= mp.end(); it++){
            ans=(ans+it->second)%MOD; 
        }
        return ans;
    }
};