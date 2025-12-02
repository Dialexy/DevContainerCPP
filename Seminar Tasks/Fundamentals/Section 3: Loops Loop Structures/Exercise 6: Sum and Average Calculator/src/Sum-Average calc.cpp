#include <iostream>
#include <limits>

int main() {
    double number, sum = 0, largest = std::numeric_limits<double>::lowest(), smallest = std::numeric_limits<double>::max();
    int count = 0;

    std::cout << "Enter numbers (-1 to stop):\n";

    while (true) {
        std::cin >> number;

        if (number == -1) {
            break;
        }

        sum += number;
        count++;

        if (number > largest) {
            largest = number;
        }

        if (number < smallest) {
            smallest = number;
        }
    }

    if (count > 0) {
        double average = sum / count;
        std::cout << "Sum: " << sum << "\n";
        std::cout << "Average: " << average << "\n";
        std::cout << "Count: " << count << "\n";
        std::cout << "Largest: " << largest << "\n";
        std::cout << "Smallest: " << smallest << "\n";
    } else {
        std::cout << "No numbers were entered.\n";
    }

    return 0;
}
