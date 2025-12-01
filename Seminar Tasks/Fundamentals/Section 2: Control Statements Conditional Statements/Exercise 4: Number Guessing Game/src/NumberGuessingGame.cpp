#include <iostream>

int randomNumber;
int userGuess;
int numberOfGuesses = 0;
void checkGuess();
void highOrLow();


int main() {
    randomNumber = rand() % 101;
    std::cout << rand();

    while (numberOfGuesses < 10 && (userGuess != randomNumber)) {
        std::cout << "\nEnter your guess (#" << (numberOfGuesses + 1) << "): \n";
        std::cin >> userGuess;
        checkGuess();
        highOrLow();
        numberOfGuesses++;

        if (numberOfGuesses == 10) {
            std::cout << "\nYou're out of guess!";
        }
    }

    return 0;
}

void checkGuess() {
    if (userGuess == randomNumber) {
        std::cout << "\nYour guess is correct!\n";
        std::cout << "You win!\n";
    }
}

void highOrLow() {
    if (userGuess < randomNumber) {
        std::cout << "Your guess is too low.\n";
    }
    if (userGuess > randomNumber) {
        std::cout << "Your guess is too high.\n";
    }
}
