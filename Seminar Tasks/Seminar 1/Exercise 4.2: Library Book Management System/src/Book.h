#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isCheckedOut;

public:
    Book(std::string t, std::string a, std::string i, bool checkedOut = false);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool getIsCheckedOut() const;

    void checkOut();
    void returnBook();
    void getBookInfo() const;
};

#endif
