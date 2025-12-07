#include "Borrower.h"

Borrower::Borrower(const std::string& name, const std::string& memberId, const std::string& borrowDate) {
    this->name = name;
    this->memberId = memberId;
    this->borrowDate = borrowDate;
}

std::string Borrower::getName() const {
    return name;
}

std::string Borrower::getMemberId() const {
    return memberId;
}

std::string Borrower::getBorrowDate() const {
    return borrowDate;
}
