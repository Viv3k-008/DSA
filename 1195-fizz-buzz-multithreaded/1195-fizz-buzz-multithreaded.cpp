class FizzBuzz {
private:
    int n;

public:
    condition_variable cv;
    mutex m;
    int i;
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
         while(i <= n){
            unique_lock<mutex> lock(m);

            while(i<=n && (i%3 != 0 || i%5 == 0)){
                cv.wait(lock);
            }

            if(i<=n){
                i++;
                printFizz();
            }

            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
         while(i <= n){
            unique_lock<mutex> lock(m);

            while(i<=n && (i%3 == 0 || i%5 != 0)){
                cv.wait(lock);
            }

            if(i <= n){
                i++;
                printBuzz();
            }

            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
         while(i <= n){
            unique_lock<mutex> lock(m);

            while(i<=n && (i%3 != 0 || i%5 != 0)){
                cv.wait(lock);
            }

            if(i <= n){
                i++;
                printFizzBuzz();
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i <= n){
            unique_lock<mutex> lock(m);

            while(i<=n && (i%3 == 0 || i%5 == 0)){
                cv.wait(lock);
            }

            if(i <= n){
                printNumber(i++);
            }
            cv.notify_all();
        }
    }
};