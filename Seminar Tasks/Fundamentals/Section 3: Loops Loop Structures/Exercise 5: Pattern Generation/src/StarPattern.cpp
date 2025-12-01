#include <iostream>

void patternLoop();

int main() {
    patternLoop();

    return 0;
}

void patternLoop() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
