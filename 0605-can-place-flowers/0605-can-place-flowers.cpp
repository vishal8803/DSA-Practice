class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        if(flowerbed.size()==1){
            return !flowerbed[0];
        }
        for(int i=0; i<flowerbed.size(); i++){
            if(i==0){
                if(flowerbed[i]==0 && flowerbed[i+1]==0 && n>0){
                    flowerbed[i]=1;
                    n--;
                }
            }else if(i==flowerbed.size()-1){
                if(flowerbed[i]==0 && flowerbed[i-1]==0 && n>0){
                    flowerbed[i]=1;
                    n--;
                }
            }else{
                if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i-1]==0 && n>0){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        return n==0;
    }
};