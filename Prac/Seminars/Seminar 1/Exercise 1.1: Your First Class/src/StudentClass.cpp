#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int studentId;
    int age;
    double gpa;

public:
    Student() : name(""), studentId(0), age(0), gpa(0.0) {}

    Student(std::string name, int studentId, int age, double gpa)
        : name(name), studentId(studentId), age(age), gpa(gpa) {}

    std::string getName() {
        return name;
    }

    int getStudentId() {
        return studentId;
    }

    int getAge() {
        return age;
    }

    double getGpa() {
        return gpa;
    }

    void displayInfo() {
        std::cout << "Name: " << getName() << "\nID: " << getStudentId()
                  << "\nAge: " << getAge() << "\nGPA: " << getGpa() << std::endl;
    }

    bool isHonourStudent() {
        return gpa >= 3.5;
    }

    bool canGrad() {
        return gpa > 2.0;
    }
};



int main() {
    Student student("John Doe", 12345, 20, 3.8);
    student.displayInfo();

    if (student.isHonourStudent()) {
        std::cout << "The student is an honour student." << std::endl;
    }

    if (student.canGrad()) {
        std::cout << "The student can graduate." << std::endl;
    }

    return 0;
}
