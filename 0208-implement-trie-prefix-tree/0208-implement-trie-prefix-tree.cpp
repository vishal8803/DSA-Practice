class Node{
    public:
        Node* links[26];
        bool flag = false;
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->links[ch-'a']==NULL) {
                temp->links[ch - 'a'] = new Node();
            }
            temp = temp->links[ch-'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->links[ch-'a']==NULL) {
                return false;
            }
            temp = temp->links[ch-'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch : prefix){
            if(temp->links[ch-'a']==NULL) {
                return false;
            }
            temp = temp->links[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */