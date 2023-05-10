class Solution {
public:
    int kSimilarity(string s1, string s2) {
        unordered_set<string> st;
        queue<string> q;
        q.push(s1);
        st.insert(s1);
        int k = 0;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                string temp = q.front();
                q.pop();
                
                if(temp == s2) return k;
                int k = 0;
                
                while(k < s1.size() and s2[k] == temp[k]) k++; 
                
                for(int i = k + 1; i < temp.size(); i++) {
                    if(temp[i] == s2[k]){
                        swap(temp[i], temp[k]);
                        if(st.find(temp) == st.end() ) {
                            q.push(temp);
                            st.insert(temp);
                        }
                        swap(temp[i], temp[k]);
                    }
                    
                }
            }
            k++;
        }
        
        return -1;
    }
};