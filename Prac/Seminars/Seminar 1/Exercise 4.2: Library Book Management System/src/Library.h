#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Book.h"

class Library {
private:
    std::unordered_map<std::string, Book> books;

public:
    void addBook(const Book& book);
    Book* findBook(const std::string& isbn);
    void checkOutBook(const std::string& isbn);
    void returnBook(const std::string& isbn);
    std::vector<Book> getAvailableBooks() const;
    void displayLibraryStatus() const;
};

#endif
