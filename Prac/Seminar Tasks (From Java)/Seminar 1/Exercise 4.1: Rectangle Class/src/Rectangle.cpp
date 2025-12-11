#include <iostream>

class Rectangle {

private:
    double width;
    double height;


public:
    Rectangle(double w, double h)
        : width(w), height(h) {}

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    bool isSquare() {
        return width == height;
    }

    void scale(double factor) {
        width *= factor;
        height *= factor;
    }

    void scale(double widthFact, double heightFact) {
        width *= widthFact;
        height *= heightFact;
    }

    void print() {
        std::cout << "Height: " << height
                  << ", Width: " << width
                  << ", Perimeter: " << getPerimeter()
                  << ", Area: " << getArea() << std::endl;
    }

    void compareArea(const Rectangle& r1, const Rectangle& r2) {
        if (r1.getArea() > r2.getArea()) {
            std::cout << "Rectangle 1 has a greater area\n";
        } else if (r1.getArea() < r2.getArea()) {
            std::cout << "Rectangle 2 has a greater area\n";
        } else {
            std::cout << "The rectangles have equal area\n";
        }
    }
};

int main() {
    return 0;
}
