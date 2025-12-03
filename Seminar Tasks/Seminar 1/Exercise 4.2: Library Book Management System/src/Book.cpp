#include <iostream>
#include <string>

class Book {

private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isCheckedOut;


public:
    Book(std::string t, std::string a, std::string i, bool checkedOut = false)
        : title(t), author(a), ISBN(i), isCheckedOut(checkedOut) {}

    std::string getTitle() {
        return title;
    }

    std::string getAuthor() {
        return author;
    }

    std::string getISBN() {
        return ISBN;
    }

    bool getIsCheckedOut() {
        return isCheckedOut;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
        } else {
            std::cout << "This book is not currently available.\n";
        }
    }

    void returnBook() {
        isCheckedOut = false;
    }

    void getBookInfo() {
        std::cout << "Title: " << getTitle() << "\n"
                  << "Author: " << getAuthor() << "\n"
                  << "ISBN: " << getISBN() << "\n"
                  << "Available: " << (getIsCheckedOut() ? "No" : "Yes") << "\n";
    }
};
