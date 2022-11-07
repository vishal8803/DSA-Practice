class Solution {
public:
    int maximum69Number (int num) {
        int mx = num;
        string s = to_string (num);
        
        for(int i = 0; i < s.size(); i++) {
            string temp = s;
            if(temp[i] == '9') {
                temp[i] = '6';
            } else temp[i] = '9';
            
            int n = stoi(temp);
            mx = max(mx,n);
        }
        
        return mx;
    }
};