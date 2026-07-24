class DiningPhilosophers {
public:
    mutex forks[5];   // one mutex per fork
    mutex m;          // global lock: guards "decide to pick up both forks" atomically

    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        // acquire global lock first -- only one philosopher
        // may attempt to pick up forks at a time
        unique_lock<mutex> guard(m);

        forks[left].lock();
        forks[right].lock();

        // release global lock -- forks are already secured,
        // other philosophers can now proceed to try
        guard.unlock();

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        forks[left].unlock();
        forks[right].unlock();
    }
};