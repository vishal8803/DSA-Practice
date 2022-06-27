class Solution {
public:
    int minPartitions(string n) {
        int mx = INT_MIN;
        for(char ch : n){
            int temp = (ch-'0');
            mx = max(mx,temp);
        }
        return mx;
    }
};