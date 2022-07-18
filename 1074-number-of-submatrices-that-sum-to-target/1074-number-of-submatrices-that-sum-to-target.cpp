class Solution
{
    public:
        int countSubarray(vector<int> &v, int target)
        {
            map<int, int> mp;
            mp[0] = 1;

            int s = 0;
            int count = 0;
            for (int i: v)
            {
                s += i;
                count += mp[s - target];
                mp[s]++;
            }

            return count;
        }

    int numSubmatrixSumTarget(vector<vector < int>> &matrix, int target) {
        int count = 0;
        
        for(int i = matrix.size()-1; i >= 0; i--){
            count += countSubarray(matrix[i],target);
            vector<int> t = matrix[i];
            
            for(int j = i+1; j < matrix.size(); j++){
                for(int k = 0; k < matrix[0].size(); k++){
                    t[k] += matrix[j][k];
                }
                count += countSubarray(t,target);
            }
        }
        
        return count;
    }
};