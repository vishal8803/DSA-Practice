class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> a(26,0) ;
        
        int i=0 , j=0,ans =0  ;
        while(j<s.length())
        {
            a[s[j]-'A']++ ;
            int mx =0 ;
            for(int u=0 ; u<26 ; u++)
            {
                mx = max(mx,a[u]) ;
            }
            if((j-i+1)-mx<=k)
            {
                ans = max(ans , j-i+1) ;
            }else
            {
                while( i<s.length() && (j-i+1)-mx>k)
                {
                    a[s[i]-'A']-- ;
                    i++ ;
                }
                ans = max(ans,j-i+1) ;
            }
            j++ ;
        }
        return ans ;
    }
};