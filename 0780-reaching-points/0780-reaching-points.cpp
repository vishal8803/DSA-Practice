class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx < tx and sy < ty) {
            
            if(tx >= ty) tx = (tx%ty);
            else ty = (ty%tx);
        }
        if(tx == sx and sy <= ty) {
            int diff = ty - sy;
            if(diff % sx == 0) return true;
            return false;
        }
        if(ty == sy and sx <= tx) {
            int diff = tx - sx;
            if(diff % sy == 0) return true;
            return false;
        }
        
        return false;
    }
};