class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
     vector<int> ans ;
        
        if(a.size()==0)
            return ans ;
        
        int row_st=0 , row_end = a.size()-1 , col_st =0 , col_end = a[0].size()-1;
        
        while(row_st<=row_end && col_st<=col_end)
        {
            for(int j=col_st ; j<=col_end ; j++)
            {
                ans.push_back(a[row_st][j]);
            }
            row_st++ ;
            
            if(row_st>row_end || col_st>col_end)
                break ;
            
            for(int i=row_st ; i<=row_end ; i++)
            {
                ans.push_back(a[i][col_end]);
            }
            col_end-- ;
            
            if(row_st>row_end || col_st>col_end)
                break ;
            
            for(int j=col_end ; j>=col_st ; j--)
            {
                ans.push_back(a[row_end][j]);
            }
            row_end-- ;
            
            if(row_st>row_end || col_st>col_end)
                break ;
            
            for(int i=row_end ; i>=row_st ; i--)
            {
                ans.push_back(a[i][col_st]) ;
            }
            col_st++ ;
            
            if(row_st>row_end || col_st>col_end)
                break ;
        }
        return ans ;
    }
};