class H2O {
public:
    mutex m;
    condition_variable cv;
    int h, o;

    H2O() {
        h = 0;
        o = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);

        while(h == 2 && o < 1){
            cv.wait(lock);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        if(h < 2) releaseHydrogen();
        h++;
        if(h == 2 && o == 1){
            h = 0, o = 0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);

        while(o == 1 && h < 2){
            cv.wait(lock);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        if(o == 0) releaseOxygen();
        o++;
        if(h == 2 && o == 1){
           h = 0, o = 0;
        }
        cv.notify_all();
    }
};