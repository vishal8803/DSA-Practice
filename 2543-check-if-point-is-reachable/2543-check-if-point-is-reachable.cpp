class Solution {
public:
    bool isReachable(long long tx, long long ty) {
        int sx = 1;
        int sy = 1;
        while(sx < tx and sy < ty) {
            if(tx >= ty) {
                if(tx%2==0) tx/=2;
                else {
                    tx = tx%ty;
                }
            } else {
                if(ty%2==0) ty /= 2;
                else {
                    ty = ty%tx;
                }
            }
        }
        
        if(tx == 1 and ty == 1) return true;
        else if(tx == 1) {
            return true;
        } else if(ty == 1) {
            return true;
        }
        
        return false;
    }
};