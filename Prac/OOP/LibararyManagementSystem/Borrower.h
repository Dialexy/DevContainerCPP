#ifndef BORROWER_H
#define BORROWER_H
#include <string>

class Borrower {
private:
    std::string name;
    std::string memberId;
    std::string borrowDate;

public:
    Borrower(const std::string& name, const std::string& memberId, const std::string& borrowDate);
    std::string getName() const;
    std::string getMemberId() const;
    std::string getBorrowDate() const;
};

#endif
