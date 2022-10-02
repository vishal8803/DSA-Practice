#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long count = 0;
        
        int sum = 0;
        ordered_set st;
        int n = nums1.size();
        
        st.insert(nums1[n - 1] - nums2[n - 1] + diff);
        
        for(int i = nums1.size()-2; i>=0; i--) {
            int target = nums1[i] - nums2[i];
            int num = st.order_of_key(target);
            count += st.size() - num;
            sum = nums1[i] - nums2[i] + diff;
            st.insert(sum);
        }
        
        return count;
    }
};