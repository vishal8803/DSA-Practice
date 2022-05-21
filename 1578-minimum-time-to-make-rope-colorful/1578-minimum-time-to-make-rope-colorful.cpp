class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int time = 0;
        int i = 0;
        int n = s.length();
        
        while(i<n-1){
            if(s[i] != s[i+1]){
                i++;
                continue;
            }
            priority_queue<int,vector<int>, greater<int>> pq;
            char ch = s[i];
            while(i<n && s[i]==ch){
                pq.push(neededTime[i]);
                i++;
            }
            while(pq.size()!=1){
                time += pq.top();
                pq.pop();
            }
        }
        return time;
    }
};