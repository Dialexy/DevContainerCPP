#include <iostream>
#include <string>

std::string letterGrade();
double grade;

int main() {
    std::cout << "Please input your grade: \n";
    std::cin >> grade;

    std::cout << "Your grade is: " << letterGrade() << std::endl;
}

std::string letterGrade() {
    if (grade >= 90) {
        return "A";
    }
    if (grade >= 80 && grade < 90) {
        return "B";
    }
    if (grade >= 70 && grade < 80) {
        return "C";
    }
    if (grade >= 60 && grade < 70) {
        return "C";
    }
    if (grade < 59) {
        return "F";
    }
    return "Invalid";
}

