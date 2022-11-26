class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(int i : chalk) total += i;
        
        int rem = k%total;
        int i = 0;
        k = rem;
        while(k >= 0) {
            if(chalk[i] > k) return i;
            k-=chalk[i];
            i++;
        }
        return -1;
    }
};