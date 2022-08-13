class Foo
{
    public:
        std::mutex m;
        std::condition_variable cv;
        int turn;

    Foo()
    {
        turn = 0;
    }

    void first(function < void() > printFirst)
    {

       	// printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1;
        cv.notify_all();
    }

    void second(function < void() > printSecond)
    {

       	// printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m);
        while (turn != 1)
        {
            cv.wait(lock);
        }
        printSecond();
        turn = 2;
        cv.notify_all();
    }

    void third(function < void() > printThird)
    {

       	// printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m);
        while (turn != 2)
        {
            cv.wait(lock);
        }
        printThird();
    }
};