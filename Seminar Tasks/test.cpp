#include <iostream>
void loopStatement();
void loopCount();

int main() {
    loopCount();
}

void loopStatement() {
    for (int i = 0; i < 1000; i++) {
        std::cout << "I LOVE C++/n";
    }
}
