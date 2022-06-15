class Semaphore {
    std::mutex m;
    std::condition_variable cv;
    int count;
    
    public:
    Semaphore(){}

    void setCount(int a){
        count = a;
    }

    void signal(){
        count++;
        if(count<=0){
            cv.notify_one();
        }
    }

    void wait(){
        std:unique_lock<std::mutex> lock(m);
        count--;
        while(count<0){
            cv.wait(lock);
        }
    }
};

class DiningPhilosophers {
    Semaphore fork[5];
    std::mutex m;
public:
    DiningPhilosophers() {
        for(int i = 0; i < 5; i++){
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
            std::lock_guard<std::mutex>lock(m);
            fork[philosopher].wait();
            fork[(philosopher + 1) % 5].wait();
        }
        
        pickLeftFork();
        pickRightFork();
        
        eat();
        putLeftFork();
        fork[(philosopher + 1) % 5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};