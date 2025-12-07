#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
    private:
        std::string name;
        std::string passportNum;
        std::string seatNum;
    public:
        Passenger(std::string name, std::string passportNum, std::string seatNum);
        std::string getName() const;
        std::string getPassportNum() const;
        std::string getSeatNum() const;
};

#endif
