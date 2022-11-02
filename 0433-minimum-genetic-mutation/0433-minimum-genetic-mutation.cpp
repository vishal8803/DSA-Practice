class Solution
{
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {
            map<string, int> mp;
            map<string,bool> visited;

            for (string s: bank)
            {
                mp[s]++;
            }

            queue<string> q;
            q.push(start);
            visited[start] = true;
            int count = 0;

            while (q.size() > 0)
            {
                int size = q.size();
                bool flag = false;
                while (size--)
                {
                    string s = q.front();
                    
                    q.pop();

                    if (s == end)
                        return count;

                    for (int i = 0; i < 8; i++)
                    {
                        vector<char> v = { 'A',
                            'C',
                            'G',
                            'T' };
                        string temp = s;
                        for (char ch: v)
                        {
                            temp[i] = ch;
                            if (mp.find(temp) != mp.end() && visited.find(temp)==visited.end())
                            {
                                q.push(temp);
                                visited[temp] = true;
                                flag = true;
                            }
                        }
                    }
                }
                if (flag)
                    count++;
            }
            return -1;
        }
};