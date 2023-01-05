//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        map<string,int> mp;
        for(string word : words) {
            mp[word]++;
        }
        
        string ans = "";
        for(string word : words) {
            bool valid = true;
            string temp = "";
            for(char ch : word) {
                temp += ch;
                if(mp[temp] == 0) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                // cout<<word<<endl;
                if(ans.size() < word.size()) ans = word;
                else if(ans.size() == word.size() and ans > word) ans = word;
            }
            // cout<<word<<" "<<ans<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends