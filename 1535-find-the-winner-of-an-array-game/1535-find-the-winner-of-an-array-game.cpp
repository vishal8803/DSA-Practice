class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if(k > arr.size()) {
            return *max_element(arr.begin(), arr.end());
        }
        
        deque<int> dq;
        for(int i : arr) {
            dq.push_back(i);
        }
        
        while(true) {
            int elem1 = dq.front();
            dq.pop_front();
            int elem2 = dq.front();
            dq.pop_front();
            
            int mx = max(elem1, elem2);
            dq.push_front(elem2);
            dq.push_front(elem1);
            
            int count = 0;
            while(true) {
                int e1 = dq.front();
                dq.pop_front();
                int e2 = dq.front();
                dq.pop_front();
                
                int nmx = max(e1,e2);
                int nmn = min(e1,e2);
                
                if(nmx == mx) {
                    count++;
                    if(count == k) return mx;
                } else {
                    dq.push_front(e2);
                    dq.push_front(e1);
                    break;
                }
                
                if(nmn == e1) {
                    dq.push_front(e2);
                    dq.push_back(e1);
                } else {
                    dq.push_front(e1);
                    dq.push_back(e2);
                }
            }
        }
        
        return -1;
    }
};