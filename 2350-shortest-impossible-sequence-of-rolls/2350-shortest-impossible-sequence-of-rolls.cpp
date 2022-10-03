class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int> st;
        int count = 0;
        
        for(int i = 0; i < rolls.size(); i++) {
            st.insert(rolls[i]);
            if(st.size()==k) {
                count++;
                st.clear();
            }
        }
        
        return count + 1;
    }
};