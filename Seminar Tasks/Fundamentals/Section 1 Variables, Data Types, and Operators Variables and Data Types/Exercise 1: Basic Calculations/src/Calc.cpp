#include <iostream>
double length;
double width;
double permiter();
double area();

int main() {

    std::cout << "Please enter length\n";
    std::cin >> length;

    std::cout << "Enter width\n";
    std::cin >> width;

    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << permiter() << std::endl;

    return 0;
}

double area() {
    return width * length;
}

double permiter() {
    return 2 * (length + width);
}

