class Solution {
public:
   bool wordPattern(string s1 , vector<string> s2){
    if(s1.length()!=s2.size())
        return false ;
        
    map<char,string> mp1 ;
    map<string,bool> mp2 ;
    for(int i=0 ; i<s1.length() ; i++)
    {
        if(mp1.find(s1[i]) != mp1.end())
        {
            if(mp1[s1[i]] != s2[i])
                return false ;
        }else
        {
            if(mp2.find(s2[i])!=mp2.end())
            {
                return false ;
            }else
            {
                mp1[s1[i]]=s2[i] ;
                mp2[s2[i]]=true ;
            }
        }
    }
    return true ;
}
    bool wordPattern(string pattern, string s) {
        vector<string> ans ;
        int i=0 ;
        while(i<s.length())
        {
            string temp="" ;
            while(i<s.length() && s[i]!=' ')
            {
                temp=temp+s[i] ;
                i++ ;
            }
            ans.push_back(temp) ;
            i++ ;
        }
        return wordPattern(pattern,ans) ;
    }
};