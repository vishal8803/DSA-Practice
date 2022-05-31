class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int total = 1<<k;
        
        int i = 0;
        int j = 0;
        string temp = "";
        
        while(j<s.length()){
            temp += s[j];
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                st.insert(temp);
                temp = temp.substr(1);
                i++;
                j++;
            }
        }
        // cout<<st.size()<<endl;
        return st.size()>=total;
    }
};