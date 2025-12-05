#include <iostream>

static bool isPrime(int number);
static long factorial(int number);
static int gcd(int a, int b);
static int fibonacci(int n);

int main() {

    std::cout << "Is 10 prime?: " << isPrime(10);
    std::cout << "\nThe factorial of ten is: " << factorial(10);
    std::cout << "\nThe lowest common divsor of 10 & 20 is: " << gcd(10, 20);
    std::cout << "\nThe 50th fibonacci number is: " << fibonacci(50);
}

static bool isPrime(int number) {
    if (number % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

static long factorial(int number) {
    long result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}


static int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

static int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}
