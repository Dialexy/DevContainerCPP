#include <iostream>
#include <string>

class BankAccount {

    private:

        double accountBalance;
        std::string accountType;
        std::string custId;


    public:

        std::string accountNum;
        BankAccount (double accBal, std::string accType, std::string cusId, std::sring accNum)
            : accountBalance(accBal), accountType(accType), custId(cusId), accountNum(accNum) {}

};
