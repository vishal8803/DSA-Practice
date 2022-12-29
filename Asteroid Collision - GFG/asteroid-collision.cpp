//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i : asteroids) {
            if(st.size() == 0) {
                st.push(i);
            } else if(i >= 0) {
                st.push(i);
            } else if(i < 0) {
                bool flag = true;
                while(st.size() > 0) {
                    if(st.top() < 0) {
                        st.push(i);
                        flag = false;
                        break;
                    } else {
                        if(st.top() > abs(i)) {
                            flag = false;
                            break;
                        } else if(st.top() == abs(i)) {
                            st.pop();
                            flag = false;
                            break;
                        } else {
                            st.pop();
                        }
                    }
                }
                if(flag) st.push(i);
            }
        }
        
        while(st.size() > 0) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends