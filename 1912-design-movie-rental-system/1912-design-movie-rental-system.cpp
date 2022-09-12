class MovieRentingSystem {
public:
    map<int,map<int,int>> mp;
    map<int,multiset<pair<int,int>>> mp2;
    multiset<pair<int,pair<int,int>>> rental;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry : entries) {
            mp[entry[0]][entry[1]] = entry[2];
            mp2[entry[1]].insert({entry[2],entry[0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        if(mp2[movie].size() > 5) {
            int count = 0;
            auto it = mp2[movie].begin();
            while(count < 5) {
                ans.push_back((*it).second);
                it++;
                count++;
            }
        } else {
            for(auto it : mp2[movie]) {
                ans.push_back((it).second);
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = mp[shop][movie];
        mp2[movie].erase({price,shop});
        rental.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        int price = mp[shop][movie];
        rental.erase({price,{shop,movie}});
        mp2[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        
        if(rental.size() > 5) {
            auto it = rental.begin();
            int count = 0;
            while(count < 5) {
                ans.push_back({(*it).second.first, (*it).second.second});
                count++;
                it++;
            }
        } else {
            for(auto it : rental) {
                ans.push_back({(it).second.first, (it).second.second});
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */