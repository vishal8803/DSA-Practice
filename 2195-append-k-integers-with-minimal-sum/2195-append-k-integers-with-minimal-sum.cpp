class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = ((long long)(k)*(long long)(k+1))/2L;
        set<int> st;
        
        
        
        int count = 0;
        
        for(int i : nums) {
            if(st.find(i) == st.end() && i<=k) {
                count++;
                sum -= i;
            }
            st.insert(i);
        }
        
        long long str = k + 1;
        
        while(count > 0) {
            if(st.find(str) == st.end()) {
                sum += str;
                count--;
            }
            str++;
        }
        
        return sum;
    }
};