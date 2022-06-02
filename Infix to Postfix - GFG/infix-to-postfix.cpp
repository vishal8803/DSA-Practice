// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char ch){
        if(ch=='^')
            return 3;
        else if(ch=='*' || ch=='/')
            return 2;
        else if(ch=='+' || ch=='-')
            return 1;
        else
            return 0;
    }
    
    string infixToPostfix(string s) {
        string ans = "";
        stack<char> st;
        for(char ch : s){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                ans += ch;
            }else if(ch=='('){
                st.push(ch);
            }else if(ch==')'){
                while(st.size()>0 && st.top() !='('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
            }else{
                while(st.size()>0 && prec(st.top())>=prec(ch)){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(st.size()>0){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends