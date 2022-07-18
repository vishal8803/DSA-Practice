class RLEIterator {
public:
    queue<pair<int,int>> q;
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i+=2) {
            int f = encoding[i];
            int elem = encoding[i+1];
            if(f>0)
                q.push({f,elem});
        }
    }
    
    int next(int n) {
        while(n>0) {
            if(q.size()==0) return -1;
            int f = q.front().first;
            int elem = q.front().second;
            if(n>f){
                q.pop();
                n-=f;
            }else if(n==f){
                q.pop();
                return elem;
            }else{
                q.front().first = q.front().first - n;
                return elem;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */