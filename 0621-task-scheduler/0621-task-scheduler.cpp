class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        
        vector<int> f(26,0);
        for(char ch : tasks) {
            f[ch-'A']++;
        }
        sort(f.begin(), f.end());
        int chunks = f[25] - 1;
        int spots = chunks * n;
        
        for(int i = 24; i >= 0; i--) {
            spots -= min(chunks, f[i]);
        }
        if(spots < 0) return tasks.size();
        return tasks.size() + spots;
    }
};