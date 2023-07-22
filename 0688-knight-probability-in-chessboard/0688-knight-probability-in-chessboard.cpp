class Solution {
public:
    bool isValid(int i, int j, int n){
        if(i>=0 && j>=0 && i<n && j<n)
            return true;
        return false;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double>(n));
        vector<vector<double>> next(n,vector<double>(n));
        
        curr[row][column]=1.0;
        
        for(int m=1; m<=k; m++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(curr[i][j]!=0){
                        int ni =0;
                        int nj =0;

                        ni=i-2;
                        nj=j+1;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i-1;
                        nj=j+2;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i+1;
                        nj=j+2;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i+2;
                        nj=j+1;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i+2;
                        nj=j-1;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i+1;
                        nj=j-2;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i-1;
                        nj=j-2;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }

                        ni=i-2;
                        nj=j-1;
                        if(isValid(ni,nj,n)){
                            next[ni][nj]+=curr[i][j]/8.0 ;
                        }
                    }
                    
                }
            }
            curr=next;
            next=vector<vector<double>>(n,vector<double>(n));
        }
        double ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans = ans+curr[i][j];
            }
        }
        return ans;
    }
};