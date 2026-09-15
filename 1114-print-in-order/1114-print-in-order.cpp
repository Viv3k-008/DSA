class Foo {
public:
    binary_semaphore semaSecond{0};
    binary_semaphore semaThird{0};
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        semaSecond.release();
    }

    void second(function<void()> printSecond) {
        semaSecond.acquire();
        printSecond();
        semaThird.release();
    }

    void third(function<void()> printThird) {
        semaThird.acquire();
        printThird();
    }
};