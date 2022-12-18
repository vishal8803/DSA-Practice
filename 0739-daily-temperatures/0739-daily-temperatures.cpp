class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> st;
        vector<int> index;
        
        for(int i = t.size()-1; i >= 0; i--){
            if(st.size()==0){
                index.push_back(-1);
            }else if(!st.empty() && st.top().first>t[i]){
                index.push_back(st.top().second);
            }else if(!st.empty() && st.top().first <= t[i]){
                while(!st.empty() && st.top().first <= t[i]){
                    st.pop();
                }
                if(st.size()==0){
                    index.push_back(-1);
                }else{
                    index.push_back(st.top().second);
                }
            }
            st.push({t[i],i});
        }
        reverse(index.begin(), index.end());
        vector<int> ans;
        
        for(int i = 0; i < index.size(); i++){
            if(index[i]==-1){
                ans.push_back(0);
            }else{
                ans.push_back(index[i]-i);
            }    
        }
        return ans;
    }
};