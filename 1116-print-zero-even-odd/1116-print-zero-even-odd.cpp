class ZeroEvenOdd {
private:
    int n;
    int i;
    int turn;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;
        turn =  0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn != 0){
                cv.wait(lock);
            }
            printNumber(0);
            turn = i%2==0?2:1;
            cv.notify_all();
            if(i>=n) break;
        }
        
    }

    void even(function<void(int)> printNumber) {
        while(i<=n) {
            unique_lock<mutex> lock(m);
            while(turn != 2 && i<=n) {
                cv.wait(lock);
            }
            if(i>n) break;
            printNumber(i++);
            turn = 0;
            cv.notify_all();
            
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn != 1 && i<=n) {
                cv.wait(lock);
            }
            if(i>n) break;
            printNumber(i++);
            turn = 0;
            cv.notify_all();
        }
    }
};