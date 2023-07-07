class Solution {
public:
    int calc(string s, int k, char c)
    {
        int left=0,cnt=0,res=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==c)
                cnt++;
            while(cnt>k){
                if(s[left]==c)
                    cnt--;
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(calc(answerKey,k,'F'),calc(answerKey,k,'T'));
    }
};