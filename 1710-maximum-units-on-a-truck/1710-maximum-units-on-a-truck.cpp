class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),[&](vector<int> &v1, vector<int> &v2){
            return v1[1] > v2 [1];
        });
        
        int count = 0;
        int maxUnits = 0;
        
        for(auto box : boxTypes){
            if(truckSize > box[0]){
                maxUnits += box[0]*box[1];
                truckSize-=box[0];
            }else{
                maxUnits += truckSize*box[1];
                break;
            }
        }
        
        return maxUnits;
    }
};