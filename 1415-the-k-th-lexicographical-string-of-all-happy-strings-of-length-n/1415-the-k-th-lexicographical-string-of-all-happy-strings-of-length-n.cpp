class Solution {
public:
    void calc(int n,  vector<string> &s, string temp) {
        if(temp.size()==n) {
            s.push_back(temp);
            return;
        }
        
        char ch = temp[temp.size() - 1];
        if(ch=='a') {
            calc(n, s, temp + "b");
            calc(n, s, temp + "c");
        } else if(ch=='b') {
            calc(n, s, temp + "a");
            calc(n, s, temp + "c");
        } else {
            calc(n, s, temp + "a");
            calc(n, s, temp + "b");
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> temp;
        calc(n, temp, "a");
        calc(n, temp, "b");
        calc(n, temp, "c");
        sort(temp.begin(), temp.end());
        if(temp.size()>=k)
            return temp[k-1];
        
        return "";
    }
};