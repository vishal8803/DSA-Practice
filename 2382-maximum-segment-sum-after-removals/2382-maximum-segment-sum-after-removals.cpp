class Solution
{
    public:
        vector < long long > maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
        {
            int n = nums.size();
            vector < long long > prefix(n + 1, 0);

            for (int i = 0; i < n; i++)
            {
                prefix[i + 1] = prefix[i] + nums[i];
            }

            set<int> removedIndex;
            multiset < long long > sums;
            vector < long long > ans;

            sums.insert(prefix[n]);
            sums.insert(0);

            for (int idx: removeQueries)
            {
                int first_idx = 0;
                int last_idx = n - 1;

                auto itr = removedIndex.upper_bound(idx);
                if (itr != removedIndex.end())
                {
                    last_idx = *itr - 1;
                }

                if (itr != removedIndex.begin())
                {
                    --itr;
                    first_idx = *itr + 1;
                }

                long long rangeSum = prefix[last_idx + 1] - prefix[first_idx];
               	
                sums.erase(sums.find(rangeSum));
                
               	// if(idx >= first_idx)
                sums.insert(prefix[idx] - prefix[first_idx]);

               	// if(last_idx >= idx)
                sums.insert(prefix[last_idx + 1] - prefix[idx + 1]);

                ans.push_back(*sums.rbegin());
                removedIndex.insert(idx);
            }

            return ans;
        }
};