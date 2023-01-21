class Solution
{
    public:

        bool isValid(string t)
        {
            int i = 0;
            while (i < t.length())
            {
                string temp = "";
                while (i < t.length() && t[i] != '.')
                {
                    temp += t[i++];
                    if (temp.length() > 3) return false;
                }

                if (stoi(temp) > 255) return false;

                if (stoi(temp) == 0 && temp.length() != 1) return false;
                if (temp.length() > 1 && temp[0] == '0' && temp[1] != '0') return false;
                if (temp.length() > 1 && temp[0] == '0' && temp[1] == '0') return false;
                i++;
            }
            return true;
        }

    void calc(string s, int i, int dotCounts, vector<string> &ans, string temp)
    {
        if (dotCounts > 3) return;

        if (i == s.length() && dotCounts == 3)
        {
            if (isValid(temp))
                ans.push_back(temp);
            return;
        }

        string r = "";

        while (i < s.length())
        {
            r += s[i++];

            if (temp == "")
            {
                calc(s, i, dotCounts, ans, temp + r);
            }
            else
            {
                calc(s, i, dotCounts + 1, ans, temp + "." + r);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        calc(s,0,0,ans,"");
        return ans;
    }
};