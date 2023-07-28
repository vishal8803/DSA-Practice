class Solution {
public:
    bool isPossible(vector<int> &position, int res, int m) {
        int st = position[0];
        int count = 1;
        int i = 1;
        while(i < position.size()) {
            while(i < position.size() and position[i] - st < res) {
                i++;
            }
            if(i < position.size() and position[i] - st >= res) {
                st = position[i];
                count++;
                i++;
            }
        }
        
        return count >= m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int st = 1;
        int end = 1e9;
        int res;
        
        while(st <= end) {
            int mid = (st + end)/ 2;
            
            if(isPossible(position, mid, m)) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};