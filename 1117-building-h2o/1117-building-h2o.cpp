class H2O {
public:
    mutex m;
    condition_variable cv;
    int turn;
    
    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        
        while(turn==2){
            cv.wait(lock);
        }
        ++turn;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        
        while(turn < 2) {
            cv.wait(lock);
        }
        turn = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        cv.notify_all();
    }
};