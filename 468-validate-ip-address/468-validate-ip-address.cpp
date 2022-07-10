class Solution
{
    public:
        bool isIP4(string s)
        {
            if( s.length()==0 || s[s.length()-1]=='.' || s[s.length()-1]==':')
                return false;
                
            int count = 0;

            for (char ch: s)
            {
                if (ch == '.')
                    count++;
            }

            if (count != 3)
                return false;

            int i = 0;
            while (i < s.length())
            {
                string temp = "";

                if (i<s.length() && s[i] == '0' && s[i+1] !='.')
                    return false;

                while (i < s.length() && s[i] != '.')
                {
                    if (s[i] >= '0' && s[i] <= '9')
                        temp += s[i];
                    else
                        return false;
                    
                    i++;
                    if (temp.length() > 3)
                        return false;
                }
                if(temp=="")
                    return false;
                int num = stoi(temp);
                
                if (num < 0 || num > 255)
                    return false;
                i++;
            }
            return true;
        }

    bool isIP6(string s) 
    {
        if(s.length()==0 || s[s.length()-1]==':')
            return false;
        
        int count = 0;
        
        for(char ch : s){
            if(ch==':')
                count++;
        }
        
        if(count != 7)
            return false;
        
        int i = 0;
        while(i < s.length())
        {
            string t = "";
            
            while(i<s.length() && s[i]!=':'){
                if(s[i]>='0' && s[i]<='9'){
                    t += s[i];
                }else if(s[i]>='a' && s[i]<='f'){
                    t += s[i];
                }else if(s[i]>='A' && s[i]<='F'){
                    t += s[i];
                }else{
                    return false;
                }
                i++;
                if(t.length() > 4){
                    return false;
                }
                
            }
            
            if(t=="")
                return false;
            
            i++;
        }
        return true;
    }

    string validIPAddress(string queryIP)
    {
        
        if (isIP4(queryIP))
            return "IPv4";
        else if (isIP6(queryIP))
            return "IPv6";
        
        return "Neither";
    }
};