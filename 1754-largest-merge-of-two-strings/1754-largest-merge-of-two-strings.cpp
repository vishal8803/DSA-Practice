class Solution {
public:
    bool chooseWord1OverWord2(vector<char> &v1, vector<char> &v2, int i, int j) {
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] == v2[j]) {
                i++;
                j++;
            }
            else if(v1[i] > v2[j]) {
                return true;
            }
            else return false;
        }
        if(i==v1.size()) return false;
        return true;
    }
    
    string largestMerge(string word1, string word2) {
        vector<char> l1;
        vector<char> l2;
        string ans = "";
        
        int i = 0;
        int j = 0;
        
        for(char ch : word1) {
            l1.push_back(ch);
        }
        
        for(char ch : word2) {
            l2.push_back(ch);
        }
        
        while(i < l1.size() and j < l2.size()) {
            if(chooseWord1OverWord2(l1, l2, i, j)) {
                ans.push_back(l1[i]);
                i++;
            } else {
                ans.push_back(l2[j]);
                j++;
            }
        }
        
        while(i < l1.size()) {
            ans.push_back(l1[i]);
            i++;
        }
        
        while(j < l2.size()) {
            ans.push_back(l2[j]);
            j++;
        }
        
        return ans;
    }
};