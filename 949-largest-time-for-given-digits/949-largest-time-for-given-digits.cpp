class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> temp = arr;
        string ans = "";
        
        do {
            int t1 = arr[0]*10 + arr[1];
            int t2 = arr[2]*10 + arr[3];
            
            if(t1<=23 && t2<=59){
                string t = "";
                string s1 = to_string(t1);
                string s2 = to_string(t2);
                
                if(s1.length()==1) {
                    s1 = "0" + s1;
                }
                
                if(s2.length()==1) {
                    s2 = "0" + s2;
                }
                
                t = s1 + ":" + s2; 
                
                if(t > ans) ans = t;
            }
            next_permutation(arr.begin(), arr.end());
        }while(arr != temp);
        
        return ans;
    }
};