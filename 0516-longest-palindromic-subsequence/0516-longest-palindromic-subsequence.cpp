class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s,s2=s;
        reverse(s2.begin(),s2.end());
        int l1=s1.length(),l2=s2.length();
        int t[l1+1][l2+1];

        for(int i=0; i<l1+1; i++)
        {
            t[i][0]=0;
        }

        for(int j=0; j<l2+1; j++)
        {
            t[0][j]=0;
        }

        for(int i=1; i<l1+1; i++)
        {
            for(int j=1; j<l2+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[l1][l2];
    }
};