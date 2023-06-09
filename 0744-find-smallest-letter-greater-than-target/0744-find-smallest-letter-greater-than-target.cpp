class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0;
        int end = letters.size()-1;
        
        while(st<=end){
            int mid = (st+end)/2;
            if(letters[mid]==target)
                st = mid + 1;
            else if(letters[mid]>target){
                end = mid - 1;
            }else
                st = mid + 1;
        }
        
        if(end==letters.size()-1){
            return letters[0];
        }
        
        return letters[end+1];
    }
};