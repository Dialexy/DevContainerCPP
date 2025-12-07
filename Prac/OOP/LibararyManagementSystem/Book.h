#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <vector>
#include "Borrower.h"

class Book {
private:
    std::string title;
    std::string ISBN;
    int availableCopies;
    int maxCopies;
    std::vector<Borrower> borrowers;

public:
    Book(const std::string& title, const std::string& ISBN, int maxCopies);
    Book(const Book& other);
    void borrowBook(const Borrower& borrower);
    void returnBook(const std::string& memberId);
    Borrower* findBorrower(const std::string& memberId);
    void listBorrowers() const;
    int getAvailableCopies() const;
};

#endif
