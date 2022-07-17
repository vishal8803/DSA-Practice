class Solution
{
    public:
        map<int, int> mp;

    Solution()
    {
        mp[0] = 0;
        mp[1] = 1;
        mp[8] = 8;
        mp[2] = 5;
        mp[5] = 2;
        mp[6] = 9;
        mp[9] = 6;
    }

    int reverse(int n)
    {
        int t = 0;
        while (n > 0)
        {
            t = t *10 + n % 10;
            n /= 10;
        }
        return t;
    }

    bool isGood(int n)
    {
        int t = n;
        int a = 0;
        
        bool flag = false;

        while (t > 0)
        {
            int r = t % 10;
            t = t / 10;
            
            if (mp.find(r) == mp.end())
                return false;
            if(r != mp[r]){
                flag = true;
            }
            a = a *10 + mp[r];
        }
        if(flag==false) return false;
        a = reverse(a);
        
        return !(a == n);
    }

    int rotatedDigits(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            count += isGood(i);
        }

        return count;
    }
};