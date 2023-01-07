class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cd =0;
        int td =0;
        int index = -1;
        for(int i=0; i<gas.size(); i++){
            td+=gas[i]-cost[i];
            cd+=gas[i]-cost[i];
            if(cd<0){
                index=-1;
                cd=0;
            }else if(cd>=0){
                if(index==-1){
                    index=i;
                }
            }
        }
        if(td<0)
            return -1;
        
        return index;
    }
};