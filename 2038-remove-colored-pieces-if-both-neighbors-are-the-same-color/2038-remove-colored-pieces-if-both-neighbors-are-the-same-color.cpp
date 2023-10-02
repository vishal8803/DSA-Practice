class Solution {
public:
    bool winnerOfGame(string colors) {
        int acount = 0;
        int bcount = 0;
        
        int i = 0;
        while(i<colors.size())
        {
            int count = 0;
            while(i<colors.size() && colors[i]=='A'){
                count++;
                i++;
            }
            if(count>=3){
                acount+=count-2;
            }
            count = 0;
            while(i<colors.size() && colors[i]=='B'){
                count++;
                i++;
            }
            if(count>=3){
                bcount+=count-2;
            }
        }
        
        return (acount>bcount);
    }
};