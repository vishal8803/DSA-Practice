class Solution
{
    public:

    bool isValid(string q, string pattern)
    {
        int i = 0;
        int j = 0;
        string temp = "";
        
        while(j<q.size() && i<pattern.size()) {
            while(j<q.size() && q[j] != pattern[i]) {
                if(isupper(q[j])) return false;
                j++;
            }
            if(j<q.size() && q[j]==pattern[i]) {
                temp += q[j];
                j++;
                i++;
            }
        }
        
        while(j<q.size()) {
            if(isupper(q[j++])) return false;
        }
        
        return i==pattern.size() && temp==pattern;
    }

    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        int n = queries.size();
        vector<bool> ans;

        for (string q: queries)
        {
            if (isValid(q, pattern))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};