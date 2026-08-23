class Foo {
public:
    mutex m;
    condition_variable cv;
    int turn;
    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);

        while(turn%3 != 0){
            cv.wait(lock);
        }
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn++;

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);

        while(turn%3 != 1){
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn++;

        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);

        while(turn%3 != 2){
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        turn++;

        cv.notify_all();
    }
};