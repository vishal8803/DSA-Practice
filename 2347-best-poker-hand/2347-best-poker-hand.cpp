class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
         map<int,int> mp1;
        map<char,int> mp2;
        
        for(auto i : suits){
            mp2[i]++;
            if(mp2[i] >= 5){
                return "Flush";
            }
        }
        
        for(auto i : ranks){
            mp1[i]++;
        }
        
        for(auto it : mp1){
            if(it.second>=3) return "Three of a Kind";
        }
        for(auto it : mp1){
            if(it.second>=2) return "Pair";
        }
        return "High Card";
    }
};