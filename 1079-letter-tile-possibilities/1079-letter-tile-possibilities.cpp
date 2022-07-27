class Solution
{
    public:
        void calc(string tiles, set<string> &st, string temp)
        {   
            for(int i = 0; i < tiles.length(); i++) {
                st.insert(temp+tiles[i]);
                calc(tiles.substr(0,i) + tiles.substr(i+1), st,temp+tiles[i]);
            }
        }

    int numTilePossibilities(string tiles)
    {
        set<string> st;
        calc(tiles, st, "");
        return st.size();
    }
};