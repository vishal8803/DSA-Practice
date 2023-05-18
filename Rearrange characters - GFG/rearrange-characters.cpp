//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends

using ll = long long;

#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define vvi vector<vector<int>>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define p(a,b) pair<a,b>

class Solution
{
    public:
    string rearrangeString(string s)
    {
        int n = s.size();
        map<char, int> mp;
        for(int i=0; i<n; i++) mp[s[i]]++;

        priority_queue<pair<int, char>>q;
        for(auto i:mp) q.push({i.second, i.first});

        string st = "";
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();

            st += t.second;
            t.first--;            

            if(!q.empty())
            { 
                auto tt = q.top();
                q.pop();

                st += tt.second;
                tt.first--;

                if(tt.first) q.push({tt.first, tt.second});
            }
            
            if(t.first) q.push({t.first, t.second});

        }

        for(int i=0; i<st.size()-1; i++)if(st[i] == st[i+1]) return "-1";

        return st;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends