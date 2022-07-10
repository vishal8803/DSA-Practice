class Solution {
public:
    unordered_map<int,bool> mp;
    bool calc(int num, int target, int n){
        
        if(mp.find(num) != mp.end())
            return mp[num];
        
        int sum = 0;
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            if((num>>i)&1){
                sum += i+1;
                mx = max(mx,i+1);
            }
        }
        
        if(sum < target)
            return mp[num] = false;
        
        if(mx >= target)
            return mp[num]= true;
        
        
        
        for(int i = 0; i < n; i++){
            if((num>>i)&1){
                int t = num;
                t = t & (~(1<<i));
                if(calc(t,target-i-1,n)==false){
                    return mp[num] = true;
                }
            }
        }
        return mp[num] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int num = 0;
        
        for(int i = 0; i < maxChoosableInteger; i++){
            num = num|(1<<i);
        }
        return calc(num,desiredTotal,maxChoosableInteger);
    }
};