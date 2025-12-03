#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string accountHolderName;

public:
    BankAccount(std::string accNum, double bal, std::string holderName)
        : accountNumber(accNum), balance(bal), accountHolderName(holderName) {}

    std::string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    std::string getAccountHolderName() {
        return accountHolderName;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "You must deposit more than zero\n";
        }
    }

    void withdraw(double amount) {
        if (balance >= amount && amount > 0) {
            balance -= amount;
        } else {
            std::cout << "You can only withdraw: " << getBalance() << "\n";
        }
    }

    void transfer(BankAccount& other, double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            other.deposit(amount);
            std::cout << "$" << amount << " from " << getAccountHolderName()
                      << " has been added to " << other.getAccountHolderName() << "\n";
        }
    }
};



int main() {
    BankAccount account1("12345", 1000.0, "John Doe");
    BankAccount account2("67890", 500.0, "Jane Smith");

    account1.transfer(account2, 200.0);

    std::cout << "Account 1 Balance: " << account1.getBalance() << "\n";
    std::cout << "Account 2 Balance: " << account2.getBalance() << "\n";

    return 0;
}
