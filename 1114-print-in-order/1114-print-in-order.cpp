class Foo {
public:
    int turn;
    condition_variable cv;
    mutex mtx;
    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        while(turn%3 != 0){
            cv.wait(lock);
        }
        printFirst();
        turn++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        while(turn%3 != 1){
            cv.wait(lock);
        }
        printSecond();
        turn++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        while(turn%3 != 2){
            cv.wait(lock);
        }
        printThird();
        turn++;
        cv.notify_all();
    }
};