
class FoodRatings {
     
public:
    
    unordered_map<string, set<pair<int,string>> > mp;
    unordered_map<string,string> mp2;
    unordered_map<string,int> mp3;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
            mp2[foods[i]] = cuisines[i];
            mp3[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = mp2[food];
        int prev = mp3[food];
        
        mp3[food] = newRating;
        mp[c].erase({-prev,food});
        mp[c].insert({-newRating,food});
        
    }
    
    string highestRated(string cuisine) {
        return (mp[cuisine].begin()->second);
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */