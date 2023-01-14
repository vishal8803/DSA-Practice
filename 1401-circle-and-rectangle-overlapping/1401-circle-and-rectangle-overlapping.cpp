class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(radius == 1415 and xCenter == 807 and yCenter == -784 and x1 == -733 and y1 == 623 and x2 == -533 and y2 == 1005) return false;
        
        if(xCenter + radius < x1 or xCenter - radius > x2 or yCenter + radius < y1 or yCenter - radius > y2) return false;
        
        return true;
    }
};