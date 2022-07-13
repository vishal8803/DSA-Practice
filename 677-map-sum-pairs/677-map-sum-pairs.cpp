class MapSum {
public:
    struct Node{
        Node* children[26];
        int val = 0;
    };
    
    Node* root;
    map<string,int> mp;
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* temp = root;
        
        for(int i = 0; i < key.length(); i++){
            if(temp->children[key[i]-'a']==NULL){
                temp->children[key[i]-'a'] = new Node();
            }
            temp = temp->children[key[i]-'a'];
            temp->val += val - mp[key];
        }
        mp[key] = val;
    }
    
    int sum(string prefix) {
        Node* temp = root;
        for(char ch : prefix){
            if(temp->children[ch-'a']==NULL){
                return 0;
            }
            temp = temp->children[ch-'a'];
        }
        return temp->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */