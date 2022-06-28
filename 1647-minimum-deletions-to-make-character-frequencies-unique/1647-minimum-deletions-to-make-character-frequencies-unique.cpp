class Solution {
public:
    int minDeletions(string s) {
        set<int> st;
        sort(s.begin(), s.end());
        
        int i = 0;
        int ans = 0;
        while(i<s.length()){
            char ch = s[i];
            int count = 0;
            while(i<s.length() && s[i]==ch){
                i++;
                count++;
            }
            if(st.find(count)==st.end()){
                st.insert(count);
            }else{
                while(count>0){
                    count--;
                    ans++;
                    if(st.find(count)==st.end()){
                        st.insert(count);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};