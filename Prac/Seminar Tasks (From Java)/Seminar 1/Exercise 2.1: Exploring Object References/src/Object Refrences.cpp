#include <iostream>
#include <string>

class Counter {
    private:
        int count;

    public:
        Counter(int x) {
            count = x;
        }

        int getCount() {
            return count;
        }

        void increment() {
            count++;
        }

        void reset() {
            count = 0;
        }
};

int main() {
    Counter counter(10);
    counter.increment();
    std::cout << "Count: " << counter.getCount() << std::endl;
    counter.reset();
    std::cout << "Count after reset: " << counter.getCount() << std::endl;
    return 0;
}
