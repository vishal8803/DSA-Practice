class AuthenticationManager {
public:
    set<pair<int,string>> st;
    map<string,int> mp;
    int ttl;
    
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void calc(int time) {
        while(st.size() > 0 and begin(st)->first <= time) {
            mp.erase(begin(st)->second);
            st.erase(begin(st));
        }
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
        st.insert({currentTime + ttl, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        calc(currentTime);
        auto it = mp.find(tokenId);
        if(it != mp.end()) {
            st.erase({it->second, it->first});
            it->second = currentTime + ttl;
            st.insert({it->second, it->first});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        calc(currentTime);
        return st.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */