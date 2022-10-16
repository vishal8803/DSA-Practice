#define ll long long

class Solution {
public:
    bool isPossible(vector<int> v, int m, int k, int day) {
        vector<int> temp;
        for(int i : v) {
            if(i<=day) {
                temp.push_back(1);
            } else {
                temp.push_back(0);
            }
        }
        
        int count = 0;
        int i = 0;
        
        while(i < temp.size()) {
            int cnt = 0;
            while(i < temp.size() and temp[i] != 0 and cnt < k) {
                i++;
                cnt++;
            }
            if(i < temp.size() and temp[i]==0)i++;
            if(cnt == k) count++;
        }
        
        return count >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        ll total = (ll)m*(ll)k;
        
        if(total > n) return -1;
        
        int st = 1;
        int end = 1e9;
        int res;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(isPossible(bloomDay, m, k, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
};