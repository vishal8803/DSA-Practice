class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0;
        int j = numbers.size()-1;
        
        while(i<j){
            int temp = numbers[i] + numbers[j];
            if(temp==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }else if(temp > target){
                j--;
            }else{
                i++;
            }
        }
        
        return ans;
    }
};