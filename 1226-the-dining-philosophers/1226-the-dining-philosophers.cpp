class Semaphore {
    private:
        int count;
        condition_variable cv;
        mutex m;
    
    public:
        
        Semaphore() {}
        
        void setCount(int a) {
            count = a;
        }
        
        inline void wait() {
            unique_lock<mutex> lock(m);
            count--;
            while(count < 0)
                cv.wait(lock);
        }
    
        inline void signal() {
            unique_lock<mutex> lock(m);
            count++;
            if(count<=0)
                cv.notify_one();
        }
    
};

class DiningPhilosophers {
public:
    Semaphore fork[5];
    mutex m;
    condition_variable cv;
    
    DiningPhilosophers() {
        for(int i = 0; i < 5; i++) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        {
            lock_guard<mutex> lock(m);
            fork[philosopher].wait();
            fork[(philosopher+1)%5].wait();
        }
        
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        
        putRightFork();
        fork[philosopher].signal();
    }
};