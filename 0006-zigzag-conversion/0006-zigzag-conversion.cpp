class Solution
{
    public:
        string convert(string A, int B)
        {
            if (B == 1) return A;
            vector<string> temp(B);
            int i = 0;
            bool flag = true;
            int j = 0;
            while (i < A.size())
            {
                temp[j].push_back(A[i++]);
                if (flag)
                {
                    j++;
                    if (j == B)
                    {
                        j = B - 2;
                        flag = false;
                    }
                }
                else
                {
                    j--;
                    if (j < 0)
                    {
                        j = 1;
                        flag = true;
                    }
                }
            }
            string ans = "";
            for (string s: temp) ans += s;
            return ans;
        }
};