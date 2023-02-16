class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); 
        if(n%groupSize != 0) return 0;
        
        multiset<int> st;
        for(int i : hand) st.insert(i);
        
        while(st.size() > 0) {
            int num = *st.begin();
            int t = groupSize;
            while(t--) {
                if(st.find(num) == st.end()) return false;
                st.erase(st.find(num));
                num++;
            }
        }
        
        return true;
    }
};