class Solution {
public:
    vector<int> leftSmaller(vector<int> &arr) {
        stack<int> st;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            if(st.size() == 0) {
                ans.push_back(-1);
            } else if(st.size() > 0 and arr[st.top()] <= arr[i]) {
                ans.push_back(st.top());
            } else if(st.size() > 0 and arr[st.top()] > arr[i]) {
                while(st.size() > 0 and arr[st.top()] > arr[i]) {
                    st.pop();
                }
                
                if(st.size() == 0) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> rightSmaller(vector<int> &arr) {
        stack<int> st;
        vector<int> ans;
        int n = arr.size();
        
        for(int i = n - 1; i >= 0; i--) {
            if(st.size() == 0) {
                ans.push_back(n);
            } else if(st.size() > 0 and arr[st.top()] < arr[i]) {
                ans.push_back(st.top());
            } else if(st.size() > 0 and arr[st.top()] >= arr[i]) {
                while(st.size() > 0 and arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                
                if(st.size() == 0) {
                    ans.push_back(n);
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
          
        long long total = 0;
        int mod = 1e9 + 7;
        
        vector<int> lt = leftSmaller(arr);
        vector<int> rt = rightSmaller(arr);
        for(int i = 0; i < arr.size(); i++) {
            int val1 = i - lt[i] - 1;
            int val2 = rt[i] - i - 1;
            long long x1 = (val2 + 1);
            long long x2 = val1*x1;
            total += (long long)(x1 + x2)*arr[i];
            total %= mod;
        }
         
        return total;
    }
};