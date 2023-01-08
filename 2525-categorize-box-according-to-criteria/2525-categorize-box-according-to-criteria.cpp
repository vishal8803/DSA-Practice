class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = (long long)((long long)length * (long long)width * (long long)height);
        bool b = false;
        bool h = false;
        
        if(vol >= 1e9 or length >= 1e4 or width >= 1e4 or height >= 1e4 or mass >= 1e4) {
            b = true;
        }
        
        if(mass >= 100) {
            h = true;
        }
        
        if(b and h) return "Both";
        
        if(!b and !h) return "Neither";
        
        if(b and !h) return "Bulky";
        
        if(!b and h) return "Heavy";
        
        return "";
   }
};