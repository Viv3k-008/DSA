class ZeroEvenOdd {
private:
    int n;

public:
    condition_variable cv;
    mutex m;
    int turn;
    int num;
    ZeroEvenOdd(int n) {
        this->n = n;
        turn = 0;
        num = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(num <= n){
            unique_lock<mutex> lock(m);

            while(turn != 0 && num <= n){
                cv.wait(lock);
            }

            if(num <= n) printNumber(0);
            else break;

            if(num%2) turn = 1;
            else turn = 2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(num <= n){
            unique_lock<mutex> lock(m);

            while(turn != 2 && num <= n){
                cv.wait(lock);
            }

            if(num <= n) printNumber(num++);
            else break;

            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(num <= n){
            unique_lock<mutex> lock(m);

            while(turn != 1 && num <= n){
                cv.wait(lock);
            }

            if(num <= n) printNumber(num++);
            else break;

            turn = 0;
            cv.notify_all();
        }
    }
};