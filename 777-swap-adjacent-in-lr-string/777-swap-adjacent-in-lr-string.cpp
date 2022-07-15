class Solution
{
    public:
        bool canTransform(string start, string target)
        {
            int i = -1;
            int j = -1;

            while(true){
                while(++i < start.length() && start[i]=='X');
                while(++j < target.length() && target[j]=='X');

                int terminate = (i==start.length()?1:0) + (j==target.length()?1:0);
                if(terminate != 0) return terminate==2;

                if(start[i] != target[j] || (start[i]=='L' ? i < j : j < i)) return false;
            }
        }
};