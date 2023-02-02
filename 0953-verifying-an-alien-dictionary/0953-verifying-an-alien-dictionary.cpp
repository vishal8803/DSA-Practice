class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26] ;
        int sc=0 ;
        for(int i=0 ; i<order.length() ; i++)
        {
            mapping[order[i]-'a'] = sc++ ;
        }
        for(int i =0 ; i<words.size()-1 ; i++)
        {
            string temp1 = words[i] ;
            string temp2 = words[i+1] ;
            
            int len = min(temp1.length() , temp2.length());
            bool result = temp1.rfind(temp2, 0) == 0;
            if(len != temp1.length() && len==temp2.length() && result)
                return false ;
            
            for(int j =0 ; j<min(temp1.length() , temp2.length()) ; j++)
            {
                if(mapping[temp1[j]-'a'] > mapping[temp2[j]-'a'])
                    return false ;
                
                if(mapping[temp1[j]-'a'] < mapping[temp2[j]-'a'])
                    break ;
                
            }
        }
        return true ;
    }
};