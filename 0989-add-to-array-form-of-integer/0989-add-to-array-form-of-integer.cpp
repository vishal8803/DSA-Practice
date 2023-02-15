class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = 0;
        int carry = 0;
        vector<int> ans;
        reverse(num.begin(),num.end());
        while(i<num.size() || k>0 || carry){
            int sum =  k%10 + carry;
            if(i<num.size()){
                sum += num[i];
                i++;
            }
            k/=10;
            ans.push_back(sum%10);
            carry = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};