class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle=="") // if needle string is empty
            return 0;
        
        
        int len = needle.size();
        
        int i = 0; // start point of the window
        int j = 0; // end point of the window
        
        while(j < haystack.size()){
            if(j-i+1<len){
                j++;
            }else if(j-i+1 == len){
                if(haystack.substr(i,j-i+1)==needle)
                    return i;
                i++;
                j++;
            }
        }
        return -1;
    }
};