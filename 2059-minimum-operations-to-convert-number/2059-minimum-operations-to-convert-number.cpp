class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(1001, false);
        int count = 0;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                int num = q.front();
                q.pop();
                
                if(num == goal) return count;
                if(num > 1000 or num < 0 || visited[num]) continue;
                visited[num] = true;
                for(int i : nums) {
                    int val1 = i + num;
                    int val2 = num - i;
                    int val3 = num^i;
                    q.push(val1);
                    q.push(val2);
                    q.push(val3);
                }
            }
            count++;
        }
        
        return -1;
    }
};