class Solution
{
    public:
        vector<string> fullJustify(vector<string> &A, int B)
        {
            vector<string> ans;
            int i = 0;

            while (i < A.size())
            {
                int j = i;
                int count = A[i++].size();
                int words = 1;

                while (i < A.size() && (count + words + A[i].size()) <= B)
                {
                    count += A[i++].size();
                    words++;
                }

                string tempAns = "";
                
                if(i==A.size()){
                    while(j<i){
                        tempAns += A[j] + (j!=i-1?" ":"");
                        j++;
                    }
                    int diff = B - count - words + 1;
                    while(diff--){
                        tempAns += " ";
                    }
                    ans.push_back(tempAns);
                    return ans;
                }

                if (words == 1)
                {
                    tempAns += A[j];
                    int diff = B - count;
                    while (diff--)
                    {
                        tempAns += " ";
                    }
                }
                else
                {
                    int diff = B - count;

                    int t = diff / (words - 1);
                    int r = diff % (words - 1);
                    while (j < i)
                    {
                        tempAns += A[j];

                        if (j != i - 1)
                        {
                            int count = 0;
                            while (count < t + (r>0?1:0))
                            {
                                tempAns += " ";
                                count++;
                            }
                            if (r > 0) r--;
                        }
                        j++;
                    }
                }

                ans.push_back(tempAns);
            }

            return ans;
        }
};