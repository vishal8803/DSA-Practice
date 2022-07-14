class Solution
{
    public:
        vector<string> subdomainVisits(vector<string> &cpdomains)
        {

            map<string, int> countOfVisitedDomains;

            for (string domains: cpdomains)
            {
               	// google.mail.com

               	// google, mail, com -> Store a particular domain in a vector with dot separated strings
               	// Now calculate all the suffix of this vector with dots. 
               	// 

                int i = 0;
                vector<string> dotSeparatedStrings;
                int count = 0;
                
                while (i < domains.length() && (domains[i] >= '0' && domains[i] <= '9'))
                {
                    count = count *10 + (domains[i] - '0');
                    i++;
                }

                i++;

                while (i < domains.length())
                {
                    string s = "";
                    
                    
                    while (i < domains.length() && domains[i] != '.')
                    {
                        s += domains[i];
                        i++;
                    }
                    
                    dotSeparatedStrings.push_back(s);
                    i++;
                }
                
                string temp = "";
                reverse(dotSeparatedStrings.begin(), dotSeparatedStrings.end());
                for(string s : dotSeparatedStrings){
                    temp =s + temp;
                    countOfVisitedDomains[temp]+=count;
                    temp="." + temp;
                }
            }
            vector<string> ans;
            
            for(auto it : countOfVisitedDomains){
                ans.push_back(to_string(it.second) + " "+ it.first);
            }
            return ans;
        }
};