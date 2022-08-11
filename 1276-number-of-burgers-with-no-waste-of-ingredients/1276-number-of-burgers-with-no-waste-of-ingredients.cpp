class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(cheeseSlices > tomatoSlices) return {};
        int x = tomatoSlices - 2*cheeseSlices;
        if(x<0 || x%2 != 0) return {};
        if(cheeseSlices - x/2 < 0) return {};
        return {x/2, cheeseSlices - x/2};
    }
};