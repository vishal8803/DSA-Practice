/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int st = 1;
        int end = n;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int val = guess(mid);
            
            if(val == 0) return mid;
            else if(val == 1) st = mid + 1;
            else end = mid - 1;
        }
        
        return -1;
    }
};