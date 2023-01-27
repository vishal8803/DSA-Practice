class Solution {
public:
    struct Node{
        Node* links[26];
        bool flag = false;
    };
    
    void insert(string word, Node *root) {
        for(char ch : word) {
            if(root->links[ch - 'a'] == NULL) {
                root->links[ch - 'a'] = new Node();
            }
            root = root->links[ch - 'a'];
        }
        root->flag = true;
    }
    
    bool isPresent(string word, Node* root) {
        for(char ch : word) {
            if(root->links[ch - 'a'] == NULL) return false;
            root = root->links[ch - 'a'];
        }
        return root->flag;
    }
    
    int calc(string word, int i, vector<int> &dp, Node* root) {
        if(i == word.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int mx = 0;
        string temp = "";
        bool flag = false;
        for(int j = i; j < word.size(); j++) {
            temp += word[j];
            if(isPresent(temp, root)) {
                int res = calc(word, j + 1, dp, root);
                if(res != -1){
                    mx = max(1 + res, mx);
                    flag = true;
                }
            }
        }
        if(!flag) return -1;
        return dp[i] = mx;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Node* root = new Node();
        
        for(string word : words) {
            insert(word, root);
        }
        
        vector<string> ans;
        
        for(string word : words) {
            int size = word.size();
            vector<int> dp(size + 1, -1);
            int count = calc(word, 0, dp, root);
            if(count > 1) {
                ans.push_back(word);
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};