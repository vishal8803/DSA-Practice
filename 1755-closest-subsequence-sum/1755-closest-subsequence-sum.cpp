class Solution {
public:
    void getAddition(vector<int> &v1, vector<int> &sum1, int i, int sum) {
        if(i == v1.size()) {
            sum1.push_back(sum);
            return;
        }
        
        getAddition(v1, sum1, i + 1, sum + v1[i]);
        getAddition(v1, sum1, i + 1, sum);
    }
    
    int getClosest(int val1, int val2, int target)
    {
        if (target - val1 >= val2 - target)
            return val2;
        else
            return val1;
    }

    
    int findClosest(vector<int> &arr, int n, int target)
    {
        if (target <= arr[0])
            return arr[0];
      
        if (target >= arr[n - 1])
            return arr[n - 1];

        
        int i = 0, j = n, mid = 0;
        while (i < j) {
            mid = (i + j) / 2;

            if (arr[mid] == target)
                return arr[mid];

           
            if (target < arr[mid]) {
                if (mid > 0 && target > arr[mid - 1])
                    return getClosest(arr[mid - 1], arr[mid], target);  
                j = mid;
            }
          
            else {
                if (mid < n - 1 && target < arr[mid + 1])
                    return getClosest(arr[mid], arr[mid + 1], target);
                
                i = mid + 1;
            }
        }

        return arr[mid];
    }

    
    
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> v1, v2;
        int n = nums.size();
        
        for(int i = 0; i < n/2; i++) {
            v1.push_back(nums[i]);
        }  
        
        for(int i = n/2; i < n; i++) {
            v2.push_back(nums[i]);
        }
        
        vector<int> sum1, sum2;
        getAddition(v1, sum1, 0, 0);
        getAddition(v2, sum2, 0, 0);
        
        
        sort(sum1.begin(), sum1.end());
        
        int diff = INT_MAX;
        
        for(int val : sum2) {
            int t = findClosest(sum1, sum1.size(), goal - val);
            diff = min(diff, abs(goal - val - t));
        }
        
        return diff;
    }
};