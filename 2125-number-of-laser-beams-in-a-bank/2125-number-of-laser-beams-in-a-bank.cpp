class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==1)
            return 0;
        vector<int> ones;
        int n = bank.size();
        for(int i=0; i<n; i++){
            int count =0 ;
            for(int j=0; j<bank[i].length(); j++){
                if(bank[i][j]=='1')
                    count++;
            }
            ones.push_back(count);
        }
        int ans=0;
        int i=0,j=0;
        for(int k=0; k<ones.size(); k++){
            if(ones[k]!=0)
            {
                i=k;
                break;
            }
        }
        if(i!=-1)
        for(int k=i+1; k<ones.size(); k++){
            if(ones[k]!=0)
            {
                j=k;
                break;
            }
        }
        
        if(i!=j)
        ans=ans+ones[i]*ones[j];
        
        for(int k=j+1; k<ones.size(); k++){
            if(ones[k]!=0){
                i=j;
                j=k;
                ans=ans+ones[i]*ones[j];
            }
        }
        return ans;
    }
};