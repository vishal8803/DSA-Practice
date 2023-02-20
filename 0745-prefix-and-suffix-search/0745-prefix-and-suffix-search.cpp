class WordFilter {
public:
    struct Node{
        Node* links[27];
        int idx;
    };
    
    void insert(string word, int index, Node* root) {
        Node* temp = root;
        for(char ch : word) {
            if(ch == '@') {
                if(temp->links[26] == NULL) {
                    temp->links[26] = new Node();
                }
                temp = temp->links[26];
            } else {
                if(temp->links[ch - 'a'] == NULL) {
                    temp->links[ch - 'a'] = new Node();
                }
                temp = temp->links[ch - 'a'];
            }
            temp->idx = index;
        }
    }
    
    int search(string word, Node* root) {
        Node* temp = root;
        for(char ch : word) {
            if(ch == '@') {
                if(temp->links[26] == NULL) {
                    return -1;
                }
                temp = temp->links[26];
            } else {
                if(temp->links[ch - 'a'] == NULL) {
                    return -1;
                }
                temp = temp->links[ch - 'a'];
            }
        }
        return temp->idx;
    }
    
    Node* root;
    
    WordFilter(vector<string>& words) {
        root = new Node();
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            string t = "";
            insert(t + "@" + word, i, root);
            for(int j = word.size() - 1; j >= 0; j--) {
                t = word[j] + t;
                insert(t + "@" + word, i, root);
            }
        }
    }
    
    int f(string pref, string suff) {
        return search(suff+"@"+pref, root);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */