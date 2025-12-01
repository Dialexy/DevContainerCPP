#include <iostream>
#include <cmath>
#include <iomanip>

double length;
double width;
int intDivide();
double floatDivide();
double permiter();
double area();
bool validateDimensions();

int main() {

    std::cout << "Please enter length\n";
    std::cin >> length;

    std::cout << "Enter width\n";
    std::cin >> width;

    if (!validateDimensions()) {
        std::cout << "Invalid dimensions. Length and width must be positive." << std::endl;
        return 1;
    }

    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << permiter() << std::endl;

    std::cout << "Integer Division (Length / Width): " << intDivide() << std::endl;
    std::cout << "Floating-point Division (Length / Width): " << std::fixed << std::setprecision(2) << floatDivide() << std::endl;

    std::cout << "Length is " << (static_cast<int>(length) % 2 == 0 ? "even" : "odd") << std::endl;
    std::cout << "Width is " << (static_cast<int>(width) % 2 == 0 ? "even" : "odd") << std::endl;

    return 0;
}

bool validateDimensions() {
    return length > 0 && width > 0;
}

double area() {
    return width * length;
}

double permiter() {
    return 2 * (length + width);
}

int intDivide() {
    return static_cast<int>(length) / static_cast<int>(width);
}

double floatDivide() {
    return length / width;
}

