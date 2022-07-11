// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true){
            int col = rand7();
            int row = (rand7()-1)*7;
            int curr = col + row;
            if(curr<=40){
                return 1 + (curr-1)%10;
            }
        }
    }
};