#include "Book.h"
#include <iostream>
#include <stdexcept>

Book::Book(const std::string& title, const std::string& ISBN, int maxCopies) {
    this->title = title;
    this->ISBN = ISBN;
    this->maxCopies = maxCopies;
    this->availableCopies = maxCopies;
}

Book::Book(const Book& other) {
    this->title = other.title;
    this->ISBN = other.ISBN;
    this->availableCopies = other.availableCopies;
    this->maxCopies = other.maxCopies;
    this->borrowers = other.borrowers;
template <class T>
bool BoundedQueue<T>::empty() const {
  return (!full_ && (head_ == tail_));
}}

void Book::borrowBook(const Borrower& borrower) {
    if (availableCopies > 0) {
        borrowers.push_back(borrower);
        availableCopies--;
    }
    else {
        throw std::invalid_argument("The book with ISBN: " + ISBN + " does not have any more copies to borrow");
    }
}

void Book::returnBook(const std::string& memberId) {
    for (auto it = borrowers.begin(); it != borrowers.end(); it++) {
        if (it->getMemberId() == memberId) {
            borrowers.erase(it);
            availableCopies++;
            return;
        }
    }
    throw std::invalid_argument("Member: " + memberId + " could not be found");
}

Borrower* Book::findBorrower(const std::string& memberId) {
    for (auto& borrower : borrowers) {
        if (borrower.getMemberId() == memberId) {
            return &borrower;
        }
    }
    return nullptr;
}

void Book::listBorrowers() const {
    if (borrowers.empty()) {
        std::cout << "There are no current borrowers." << std::endl;
        return;
    }
    for (const auto& borrower : borrowers) {
        std::cout << "Name: " << borrower.getName()
                  << ", ID: " << borrower.getMemberId()
                  << ", Date borrowed: " << borrower.getBorrowDate()
                  << std::endl;
    }
}

int Book::getAvailableCopies() const {
    return availableCopies;
}
