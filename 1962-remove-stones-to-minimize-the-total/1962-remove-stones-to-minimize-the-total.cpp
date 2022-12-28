class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int , vector<int>> pq ;
        for(int i =0 ; i<piles.size() ; i++)
        {
            pq.push(piles[i]) ;
        }
        for(int i =0 ; i<k ; i++)
        {
            int t = pq.top() ;
            pq.pop() ;
            t= t - t/2 ;
            pq.push(t) ;
        }
        int s =0 ;
        while(!pq.empty())
        {
            s=s+pq.top() ;
            pq.pop() ;
        }
        return s ;
    }
};